// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class UE5MultPlugin : ModuleRules
{
	public UE5MultPlugin(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "EnhancedInput", 
			"UMG", "ItemPlugin", "SkillPlugin", "OnlineSubsystem", "OnlineSubsystemSteam"});

        DynamicallyLoadedModuleNames.Add("OnlineSubsystemNull");
    }
}
