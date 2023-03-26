// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CourseInfo.generated.h"

/**
 * CoureInfo가 변경되는 event에 대한 delegate이다
 * Signature라는 접미사를 붙히는건 관행이다.
 */
DECLARE_MULTICAST_DELEGATE_TwoParams(FCourseInfoOnChangedSignature, const FString&, const FString&);

/**
 * 
 */
UCLASS()
class UNREALDELEGATE_API UCourseInfo : public UObject
{
	GENERATED_BODY()
public:
	UCourseInfo();

	FCourseInfoOnChangedSignature OnChanged;
	void ChangeCourseInfo(const FString& InSchoolName, const FString& InNewContents);
private:
	FString Contents;
	
};
