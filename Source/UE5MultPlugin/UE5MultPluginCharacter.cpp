// Copyright Epic Games, Inc. All Rights Reserved.

#include "UE5MultPluginCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "SkillManagementComponent.h"
#include "StatManagementComponent.h"
#include "MonsterStatComponent.h"
#include "MyPlayerController.h"
#include "Components/ArrowComponent.h"
#include "ActiveSkillLightning.h"
#include "ActiveSkillStorm.h"
#include "Particles/ParticleSystemComponent.h"

//////////////////////////////////////////////////////////////////////////
// AUE5MultPluginCharacter

AUE5MultPluginCharacter::AUE5MultPluginCharacter()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);
		
	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 500.0f, 0.0f); // ...at this rotation rate

	// Note: For faster iteration times these variables, and many more, can be tweaked in the Character Blueprint
	// instead of recompiling to adjust them
	GetCharacterMovement()->JumpZVelocity = 700.f;
	GetCharacterMovement()->AirControl = 0.35f;
	GetCharacterMovement()->MaxWalkSpeed = 500.f;
	GetCharacterMovement()->MinAnalogWalkSpeed = 20.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 400.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	MyArrow = CreateDefaultSubobject<UArrowComponent>(TEXT("MyArrow"));
	MyArrow->SetupAttachment(RootComponent);
	MyArrow->AddLocalOffset(FVector(0, 0, 100.0f));

	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named ThirdPersonCharacter (to avoid direct content references in C++)

	// StatManager = CreateDefaultSubobject<UStatManagementComponent>(TEXT("StatManager"));

	MonsterStat = CreateDefaultSubobject<UMonsterStatComponent>(TEXT("MonsterStat"));

	// SkillManager = CreateDefaultSubobject<USkillManagementComponent>(TEXT("SkillManager"));
}

void AUE5MultPluginCharacter::BeginPlay()
{
	// Call the base class  
	Super::BeginPlay();

	//Add Input Mapping Context
	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
		}
	}
}

void AUE5MultPluginCharacter::EventGetItem_Implementation(EItemType itemType)
{
	AMyPlayerController* PC = Cast<AMyPlayerController>(this->GetController());

	if (PC)
	{
		UStatManagementComponent* StatManager = Cast<UStatManagementComponent>(PC->FindComponentByClass<UStatManagementComponent>());
		
		if (StatManager)
		{
			if (IsValid(StatManager) == false)
			{
				return;
			}

			switch (itemType)
			{
			case EItemType::IT_RecoveryHp:
			{
				UE_LOG(LogTemp, Warning, TEXT("IT_RecoveryHp"));
				StatManager->RecurberyHp();
				break;
			}
			case EItemType::IT_RecoveryMp:
			{
				UE_LOG(LogTemp, Warning, TEXT("IT_RecoveryMp"));
				StatManager->RecurberyMp();
				break;
			}
			case EItemType::IT_SpeedUp:
			{
				UE_LOG(LogTemp, Warning, TEXT("IT_SpeedUp"));
				StatManager->BurfSpeed();
				break;
			}
			case EItemType::IT_PowerUp:
			{
				UE_LOG(LogTemp, Warning, TEXT("IT_PowerUp"));
				StatManager->BurfPower();
				break;
			}
			case EItemType::IT_Gold:
			{
				UE_LOG(LogTemp, Warning, TEXT("IT_Gold"));
				PC->Gold += 50;
				PC->OnUpdateMyGold(PC->Gold);
				break;
			}
			}
		}
	}
	
}

float AUE5MultPluginCharacter::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	UMonsterStatComponent* monsterPS = Cast<UMonsterStatComponent>(this->FindComponentByClass<UMonsterStatComponent>());
	
	if (monsterPS == nullptr)
	{
		return 0.0f;
	}
	
	monsterPS->Hp -= DamageAmount;

	UE_LOG(LogTemp, Warning, TEXT("%f"), monsterPS->Hp);

	return 0.0f;
}

void AUE5MultPluginCharacter::SpawnSkillActor()
{
	AMyPlayerController* PC = Cast<AMyPlayerController>(GetController());

	if (PC)
	{
		USkillManagementComponent* SkillManager = Cast<USkillManagementComponent>(PC->FindComponentByClass<USkillManagementComponent>());

		if (SkillManager)
		{
			SkillManager->IsCanUseLightning();

			FVector Location = MyArrow->GetComponentLocation();

			FRotator Rotation = MyArrow->GetComponentRotation();

			AActiveSkillStorm* lightning = GetWorld()->SpawnActor<AActiveSkillStorm>(Location, Rotation);

			if (lightning)
			{
				UE_LOG(LogTemp, Warning, TEXT("%s"), *lightning->SkillName);
				lightning->SkillName = "Success Spawn";
				UE_LOG(LogTemp, Warning, TEXT("%s"), *lightning->SkillName);
				UParticleSystemComponent* ParticleComponent = lightning->FindComponentByClass<UParticleSystemComponent>();
				if (ParticleComponent)
				{
					ParticleComponent->Activate();
				}
			}
		}
	}
}

//////////////////////////////////////////////////////////////////////////
// Input

void AUE5MultPluginCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// Set up action bindings
	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent)) {
		
		//Jumping
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Triggered, this, &ACharacter::Jump);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);

		//Moving
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AUE5MultPluginCharacter::Move);

		//Looking
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &AUE5MultPluginCharacter::Look);

		EnhancedInputComponent->BindAction(Test, ETriggerEvent::Started, this, &AUE5MultPluginCharacter::TestWidget);

		EnhancedInputComponent->BindAction(UseSkill, ETriggerEvent::Started, this, &AUE5MultPluginCharacter::UsingSkill);

	}

}

void AUE5MultPluginCharacter::Move(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D MovementVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	
		// get right vector 
		const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		// add movement 
		AddMovementInput(ForwardDirection, MovementVector.Y);
		AddMovementInput(RightDirection, MovementVector.X);
	}
}

void AUE5MultPluginCharacter::Look(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D LookAxisVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		// add yaw and pitch input to controller
		AddControllerYawInput(LookAxisVector.X);
		AddControllerPitchInput(LookAxisVector.Y);
	}
}

void AUE5MultPluginCharacter::TestWidget(const FInputActionValue& Value)
{
	AMyPlayerController* PlayerController = Cast<AMyPlayerController>(Controller);

	if (PlayerController)
	{
		if (PlayerController->Test == 0)
		{
			PlayerController->CreateSkillShopWidget();
			PlayerController->Test = 1;
		}
		else
		{
			PlayerController->CloseSkillShopWidget();
			PlayerController->Test = 0;
		}
	}
}

void AUE5MultPluginCharacter::UsingSkill(const FInputActionValue& Value)
{
	SpawnSkillActor();
}




