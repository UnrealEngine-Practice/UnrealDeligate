// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MyGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class UNREALDELEGATE_API UMyGameInstance final : public UGameInstance
{
	GENERATED_BODY()
public :
	UMyGameInstance();

	virtual void Init() override;

private:
	/*
	 *  SchoolName이라는 property는 기본값을 지정하지 않으면 그냥 빈 문자열이다.
	 * 생성자 코드에 기본 값을 지정할 수 있다.
	 */
	UPROPERTY()
	FString SchoolName;


	/*
	 *   Student.cpp나 Student.h에 CourseInfo.h를 추가하지 않은 것을 확인 할 수 있고,
	 *  마찬가지로 CourseInfo.h와 CourseInfo.cpp도 Student를 포함하지 않는 것을 보아
	 *  완전히 독립적으로 작성됨을 알 수 있다.
	 *   중간에서 이를 중재해주는 객체가 필요하다.
	 *  학사정보는 UObject객체이고 포인터로 이를 관리할 수 있다.
	 *
	 *  CourseInfo는 CDO안에서 (Init()메서드 내에서)생성할 수도 있지만
	 *  외부에서 필요할 때만 생성할 수도 있다.
	 *  
	 */
	UPROPERTY()
	TObjectPtr<class UCourseInfo> CourseInfo;
};
