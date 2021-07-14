// Fill out your copyright notice in the Description page of Project Settings.


#include "Utill.h"
#include "Materials/MaterialParameterCollectionInstance.h"

Utill::Utill()
{
}

Utill::~Utill()
{
}

float Utill::SetParameterByTargetedValue(float& CurrentValue, float TargetedValue, const float ChangeRate, UMaterialParameterCollectionInstance* MaterialParam, FName ParamName)
{
	float diff = TargetedValue - CurrentValue;

	if (abs(diff) > 0.1f)
	{
		float changeValue = (diff > 0.f) ? ChangeRate * 1.0f : ChangeRate * -1.0f;
		CurrentValue = CurrentValue + changeValue;
		if (ParamName != TEXT(""))
		{
			MaterialParam->SetScalarParameterValue(ParamName, CurrentValue);
		}
	}

	return CurrentValue;
}