#include "Commands/BTCommands.h"
#include "Style/BlueprintToolGraphStyle.h"

#define LOCTEXT_NAMESPACE "BTEditorCommands"

FBTCommands::FBTCommands() 
	: TCommands<FBTCommands>(
		TEXT("BTEditor"), 
		LOCTEXT("BTEditor","BTEditor Commands"),
		NAME_None, FBPGraphStyle::GetStyleSetName())
{

}

void FBTCommands::RegisterCommands()
{
	UI_COMMAND(Compile, "Compile", "Compile Blueprint Code", EUserInterfaceActionType::ToggleButton, FInputGesture());
	UI_COMMAND(Help, "Help", "Document of Blueprint Tool", EUserInterfaceActionType::ToggleButton, FInputGesture());
	UI_COMMAND(Run, "Run", "Run Blueprint Code", EUserInterfaceActionType::ToggleButton, FInputGesture());
}

#undef LOCTEXT_NAMESPACE