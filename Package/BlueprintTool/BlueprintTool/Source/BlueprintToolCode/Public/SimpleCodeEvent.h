#pragma once

#include "CoreMinimal.h"
#include "SimpleCode.h"
#include "ReflectionData/SimpleCodeEvent.Reflect.h"
#include "SimpleCodeEvent.generated.h"

UCLASS()
class BLUEPRINTTOOLCODE_API USimpleCodeEvent : public USimpleCode
{
	//保存后就会生成
	GENERATED_BODY()

public:
	GENERATED_BT_BODY()

public:

	UFUNCTION(Meta = (CodeType = "Event", Group = "MainEvent"))
	static void BlueprintGameBegins(UStaticMeshComponent* Mesh);
};