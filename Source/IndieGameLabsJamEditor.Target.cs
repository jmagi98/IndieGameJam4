// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class IndieGameLabsJamEditorTarget : TargetRules
{
	public IndieGameLabsJamEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		ExtraModuleNames.Add("IndieGameLabsJam");
	}
}
