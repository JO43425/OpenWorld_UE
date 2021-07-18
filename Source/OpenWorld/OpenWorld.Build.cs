// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class OpenWorld : ModuleRules
{
	public OpenWorld(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "UMG", "AIModule", "GamePlayTasks", "NavigationSystem" });
	}
}
