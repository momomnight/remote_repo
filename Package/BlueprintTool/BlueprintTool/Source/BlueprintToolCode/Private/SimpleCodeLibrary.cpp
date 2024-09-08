#include "SimpleCodeLibrary.h"
#include "Components\StaticMeshComponent.h"
#include "Engine\StaticMesh.h"
#include "Materials\MaterialInstance.h"
#include "Templates\Casts.h"
#include "MaterialTypes.h"

#if PLATFORM_WINDOWS
#pragma optimize("", off)
#endif // PLATFORM_WINDOWS

void USimpleCodeLibrary::SetLocation(UStaticMeshComponent* MeshComponent, FVector InLocation)
{
	if (MeshComponent)
	{
		MeshComponent->SetRelativeLocation(InLocation);
	}
}

void USimpleCodeLibrary::SetRotation(UStaticMeshComponent* MeshComponent, FRotator InRotation)
{
	if (MeshComponent)
	{
		MeshComponent->SetRelativeRotation(InRotation);
	}
}

void USimpleCodeLibrary::SetMesh(UStaticMeshComponent* MeshComponent, UStaticMesh* InMesh)
{
	if (MeshComponent)
	{
		MeshComponent->SetStaticMesh(InMesh);
	}
}

void USimpleCodeLibrary::SetMaterial(UStaticMeshComponent* MeshComponent, int32 Index, UMaterialInterface* InMaterial)
{
	if (MeshComponent)
	{
		MeshComponent->SetMaterial(Index, InMaterial);
	}
}

void USimpleCodeLibrary::SetMaterialColor(UStaticMeshComponent* MeshComponent, FName ColorName, FLinearColor Color, int32 MaterialIndex = 0)
{
	if (MeshComponent)
	{
		UMaterialInstance* MaterialInterface = Cast<UMaterialInstance>(MeshComponent->GetMaterial(MaterialIndex));
	
		if (MaterialInterface)
		{
			FMaterialParameterInfo Info;
			Info.Name = ColorName;
			Info.Index = MaterialIndex;

			FVectorParameterValue Value;
			Value.ParameterInfo = Info;
			Value.ParameterValue = Color;
			MaterialInterface->VectorParameterValues.Add(Value);
		}
	}
}
#if PLATFORM_WINDOWS
#pragma optimize("", on)
#endif // PLATFORM_WINDOWS