// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "BlueprintFunctionLibraryA.generated.h"

/**
 * 
 */

USTRUCT(BlueprintType)
struct FAverages
{
	FAverages()
		: mean(0.0f)
		, mode(0.0f)
		, median(0.0f)
	{
	};

	FAverages(float inmean, float inmode, float inmedian)
		: mean(inmean)
		, mode(inmode)
		, median(inmedian)
	{

	}



	UPROPERTY(BlueprintReadOnly)
	float mean = 0.0f;

	UPROPERTY(BlueprintReadOnly)
	float mode = 0.0f;

	UPROPERTY(BlueprintReadOnly)
	float median = 0.0f;

	GENERATED_BODY();
};



UCLASS()
class SHALLOWGROVE_API UBlueprintFunctionLibraryA : public UBlueprintFunctionLibrary
{
public:
	UFUNCTION(BlueprintCallable)
	static FString get_pointless_message();
	
	UFUNCTION(BlueprintCallable,
		BlueprintPure,
		meta = (ToolTip = "3.14 blah blah blah",
			CompactNodeTitle = "pi"))
	static double get_my_pi();

	UFUNCTION(BlueprintCallable,
		meta = (ToolTip = "calc mean median and mode for array of ints"))
	static FAverages calculate_averages(const TArray<int32>& in_vals);

private:
	static constexpr double _pi = 3.14;
	
	GENERATED_BODY()
};
