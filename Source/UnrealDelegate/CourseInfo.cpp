// Fill out your copyright notice in the Description page of Project Settings.


#include "CourseInfo.h"

UCourseInfo::UCourseInfo()
{
	Contents = TEXT("기본 학사 정보");
}

void UCourseInfo::ChangeCourseInfo(const FString& InSchoolName, const FString& InNewContents)
{
	Contents = InNewContents;

	UE_LOG(LogTemp, Log, TEXT("학새정보가 변경됨"));
	OnChanged.Broadcast(InSchoolName, Contents);
}
