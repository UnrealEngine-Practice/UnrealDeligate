// Fill out your copyright notice in the Description page of Project Settings.

#include "MyGameInstance.h"

#include "Card.h"
#include "CourseInfo.h"
#include "Student.h"
#include "Staff.h"
#include "Teacher.h"

// 클래스 생성자의 값은 CDO에 저장되고 이후에 Init함수에서 SchoolName을 바꿔도
// CDO에 저장된 기본 값은 바뀌지 않는다.
UMyGameInstance::UMyGameInstance()
{
	SchoolName = TEXT("학교");
}

void UMyGameInstance::Init()
{
	Super::Init();
	/**
	 * TODO : NewObject의 Outer?
	 * Outer를 지정해주면 MyGameInstance가 CourseInfo를 포함하도록 하게된다.
	 * this는 현재 클래스인 MyGameInstance의 객체를 의미하고 따라서
	 * CourseInfo는 MyGameInstance에 포함(composition)된다.
	 */
	CourseInfo = NewObject<UCourseInfo>(this);
	UE_LOG(LogTemp, Log, TEXT("============================================"));
	UStudent* Student1 = NewObject<UStudent>();
	UStudent* Student2 = NewObject<UStudent>();
	UStudent* Student3 = NewObject<UStudent>();
	Student1->SetName(TEXT("학생1"));
	Student2->SetName(TEXT("학생2"));
	Student3->SetName(TEXT("학생3"));

	CourseInfo->OnChanged.AddUObject(Student1, &UStudent::GetNotification);
	CourseInfo->OnChanged.AddUObject(Student2, &UStudent::GetNotification);
	CourseInfo->OnChanged.AddUObject(Student3, &UStudent::GetNotification);

	CourseInfo->ChangeCourseInfo(SchoolName, TEXT("새 학사정보"));
	UE_LOG(LogTemp, Log, TEXT("============================================"));
}
