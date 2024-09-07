// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "IPropertyTypeCustomization.h"

class FBlueprintVariableMappings : public IPropertyTypeCustomization
{
public:

	virtual void CustomizeHeader(TSharedRef<class IPropertyHandle> PropertyHandle, class FDetailWidgetRow& HeaderRow, class IPropertyTypeCustomizationUtils& CustomizationUtils) override;

	virtual void CustomizeChildren(TSharedRef<class IPropertyHandle> PropertyHandle, class IDetailChildrenBuilder& ChildBuilder, class IPropertyTypeCustomizationUtils& CustomizationUtils) override;

	static TSharedRef<IPropertyTypeCustomization> MakeInstance();

};
