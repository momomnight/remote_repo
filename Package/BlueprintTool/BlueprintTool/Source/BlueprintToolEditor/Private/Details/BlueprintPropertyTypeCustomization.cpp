#include "Details/BlueprintPropertyTypeCustomization.h"
#include "PropertyHandle.h"
#include "DetailWidgetRow.h"
#include "IPropertyTypeCustomization.h"
#include "IDetailChildrenBuilder.h"
#include "IDetailGroup.h"

#define LOCTEXT_NAMESPACE "PropertyTypeCustomization"

void FBlueprintVariableMappings::CustomizeHeader(TSharedRef<class IPropertyHandle> PropertyHandle, FDetailWidgetRow& HeaderRow, IPropertyTypeCustomizationUtils& CustomizationUtils)
{
	HeaderRow
	.WholeRowContent()
	[
		PropertyHandle->CreatePropertyNameWidget()
	];
}

void FBlueprintVariableMappings::CustomizeChildren(TSharedRef<class IPropertyHandle> PropertyHandle, IDetailChildrenBuilder& ChildBuilder, IPropertyTypeCustomizationUtils& CustomizationUtils)
{
	uint32 ChildrenNumber;
	PropertyHandle->GetNumChildren(ChildrenNumber);

	TMap<FString, IDetailGroup*> DetailGroupMapping; 

	for (uint32 I = 0; I < ChildrenNumber; I++)
	{
		TSharedPtr<IPropertyHandle> ChildHandle = PropertyHandle->GetChildHandle(I);
		
		if(ChildHandle->GetProperty())
		{
			const FString* MetaData = &ChildHandle->GetMetaData(TEXT("Test"));
			if (*MetaData != TEXT("Hide"))//为Hide则不添加属性
			{
				MetaData = &ChildHandle->GetMetaData(TEXT("Category"));
				IDetailGroup* DetailGroup;

				if (DetailGroupMapping.Contains(*MetaData))//包含该组则使用改组，不包含则添加组
				{
					DetailGroup = DetailGroupMapping[*MetaData];
				}
				else
				{
					DetailGroup = &ChildBuilder.AddGroup(**MetaData, FText::Format(LOCTEXT("Hello", "{0}"), FText::FromString(*MetaData)));
					DetailGroupMapping.Add(*MetaData, DetailGroup);
				}
				DetailGroup->AddPropertyRow(ChildHandle.ToSharedRef());
			}
		}
	}

}

TSharedRef<IPropertyTypeCustomization> FBlueprintVariableMappings::MakeInstance()
{
	return MakeShareable(new FBlueprintVariableMappings);
}

#undef LOCTEXT_NAMESPACE