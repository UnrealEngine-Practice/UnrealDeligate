// Fill out your copyright notice in the Description page of Project Settings.


#include "Student.h"
#include "Card.h"

UStudent::UStudent()
{
	Name = TEXT("이학생");
	Card->SetCardType(ECardType::Student);
}	


void UStudent::DoLesson()
{
	UE_LOG(LogTemp, Log, TEXT("%s학생이 공부를 시작했습니다."), *this->GetName());
}

void UStudent::GetNotification(const FString& School, const FString& NewCourseInfo)
{
	UE_LOG(LogTemp, Log, TEXT("[Student] 학사경고 알림 수신함 : %s"), *NewCourseInfo);
}
