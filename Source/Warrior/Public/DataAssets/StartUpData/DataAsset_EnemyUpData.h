// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DataAssets/StartUpData/DataAsset_StartUpDataBase.h"
#include "DataAsset_EnemyUpData.generated.h"

class UWarriorEnemyGameplayAbility;
/**
 * 
 */
UCLASS()
class WARRIOR_API UDataAsset_EnemyUpData : public UDataAsset_StartUpDataBase
{
	GENERATED_BODY()

public:
	virtual void GivenToAbilitySystemComponent(UWarriorAbilitySystemComponent* InASCToGiven, int32_t ApplyLevel = 1) override;
private:
	UPROPERTY(EditDefaultsOnly, Category = "StartupData")
	TArray<TSubclassOf<UWarriorEnemyGameplayAbility>> EnemyCombatAbilties;
	
	
	
};
