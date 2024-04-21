// Fill out your copyright notice in the Description page of Project Settings.


#include "BlueprintFunctionLibraryA.h"


FString UBlueprintFunctionLibraryA::get_pointless_message()
{
	return FString(TEXT("This is a message, but its means fuck all"));
}


double UBlueprintFunctionLibraryA::get_my_pi()
{
	return _pi;
}



FAverages UBlueprintFunctionLibraryA::calculate_averages(const TArray<int32>& in_vals)
{
	TArray<int32> tmp_array = in_vals;
	TMap<int32, int32> modal_count;

	float calc_mean = 0.0f;
	float calc_mode = 0.0f;
	float calc_median = 0.0f;

	float sum = 0;
	const int32 count = tmp_array.Num();

	if (count == 0)
		return FAverages(0.0f, 0.0f, 0.0f);

	tmp_array.Sort();

	for (int i = 0; i < count; ++i)
	{
		sum += tmp_array[i];

		if (modal_count.Contains(tmp_array[i]))
			modal_count[tmp_array[i]]++;
		else
			modal_count.Add(tmp_array[i], 1);
	}

	calc_mean = sum / static_cast<float>(count);

	calc_median = count % 2 != 0 ? tmp_array[count / 2]
		: static_cast<float>((tmp_array[(count / 2) - 1]
			+ tmp_array[count / 2])) / 2;

	modal_count.ValueSort([](int32 a, int32 b)
		{return a > b; });

	TArray<TPair<int32, int32>> modals = modal_count.Array();

	if (modals[0].Value == 1)
	{
		calc_mode = calc_mean;
	}
	else
	{
		int32 modal_entries = 1;
		int32 modal_sum = modals[0].Key;

		for (int i = 0; i < modals.Num(); ++i)
		{
			if (modals[i].Value != modals[0].Value)
				break;
			modal_sum += modals[i].Key;
			modal_entries++;
		}

		calc_mode = static_cast<float>(modal_sum)
			/ static_cast<float>(modal_entries);

	}

	return FAverages(calc_mean, calc_mode, calc_median);
}