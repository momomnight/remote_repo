#pragma once

class BLUEPRINTTOOLEDITOR_API FBTCommands : public TCommands<FBTCommands>
{
public:
	FBTCommands();


	virtual void RegisterCommands() override;

public:

	TSharedPtr<FUICommandInfo> Compile;

	TSharedPtr<FUICommandInfo> Help;

	TSharedPtr<FUICommandInfo> Run;

};