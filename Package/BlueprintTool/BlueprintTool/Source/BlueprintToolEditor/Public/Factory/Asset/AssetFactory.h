// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Factories/Factory.h"

#include "AssetFactory.generated.h"

UCLASS()
class UAssetFactory : public UFactory
{//不需要导出吗？
	GENERATED_BODY()

public:
	UAssetFactory();

	virtual UObject* FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, class FFeedbackContext* Warn, FName CallingContext) override;
};
