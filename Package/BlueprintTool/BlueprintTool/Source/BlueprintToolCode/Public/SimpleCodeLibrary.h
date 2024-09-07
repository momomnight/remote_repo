#pragma once

#include "CoreMinimal.h"
#include "SimpleCode.h"
#include "ReflectionData/SimpleCodeLibrary.Reflect.h"
#include "SimpleCodeLibrary.generated.h"

UCLASS()
class BLUEPRINTTOOLCODE_API USimpleCodeLibrary : public USimpleCode
{	
	//保存后就会生成
	GENERATED_BODY()

public:	
	GENERATED_BT_BODY()

public:

	UFUNCTION(Meta = (CodeType = "Description", Group = "SimpleCodeLibrary"))
	static void SetLocation(UStaticMeshComponent* MeshComponent, FVector InLocation);

	UFUNCTION(Meta = (CodeType = "Description", Group = "SimpleCodeLibrary"))
	static void SetRotation(UStaticMeshComponent* MeshComponent, FRotator InRotation);

	UFUNCTION(Meta = (CodeType = "Description", Group = "SimpleCodeLibrary"))
	static void SetMesh(UStaticMeshComponent* MeshComponent, UStaticMesh* InMesh);

	UFUNCTION(Meta = (CodeType = "Description", Group = "SimpleCodeLibrary"))
	static void SetMaterial(UStaticMeshComponent* MeshComponent, int32 Index, UMaterialInterface* InMaterial);

	UFUNCTION(Meta = (CodeType = "Description", Group = "SimpleCodeLibrary"))
	static void SetMaterialColor(UStaticMeshComponent* MeshComponent, FName ColorName, FLinearColor Color, int32 MaterialIndex);

};