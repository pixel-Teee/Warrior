// Fill out your copyright notice in the Description page of Project Settings.


#include "DataAssets/StartUpData/DataAsset_EnemyUpData.h"
#include "AbilitySystem/WarriorAbilitySystemComponent.h"
#include "AbilitySystem/Abilities/WarriorEnemyGameplayAbility.h"


void UDataAsset_EnemyUpData::GivenToAbilitySystemComponent(UWarriorAbilitySystemComponent* InASCToGiven, int32_t ApplyLevel /*= 1*/)
{
	Super::GivenToAbilitySystemComponent(InASCToGiven, ApplyLevel);

	if (!EnemyCombatAbilties.IsEmpty())
	{
		for (const TSubclassOf<UWarriorEnemyGameplayAbility>& AbilityClass : EnemyCombatAbilties)
		{
			if(!AbilityClass) continue;

			FGameplayAbilitySpec AbilitySpec(AbilityClass);
			AbilitySpec.SourceObject = InASCToGiven->GetAvatarActor();
			AbilitySpec.Level = ApplyLevel;

			InASCToGiven->GiveAbility(AbilitySpec);
		}
	}
}
