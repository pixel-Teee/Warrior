// Fill out your copyright notice in the Description page of Project Settings.


#include "DataAssets/StartUpData/DataAsset_StartUpDataBase.h"
#include "AbilitySystem/WarriorAbilitySystemComponent.h"
#include "AbilitySystem/Abilities/WarriorGameplayAbility.h"

void UDataAsset_StartUpDataBase::GivenToAbilitySystemComponent(UWarriorAbilitySystemComponent* InASCToGiven, int32_t ApplyLevel /*= 1*/)
{
	check(InASCToGiven);

	GrantAbilities(ActivateOnGivenAbilities, InASCToGiven, ApplyLevel);
	GrantAbilities(ReactiveAbilities, InASCToGiven, ApplyLevel);
}

void UDataAsset_StartUpDataBase::GrantAbilities(const TArray<TSubclassOf< UWarriorGameplayAbility>>& InAbilitiesToGive, UWarriorAbilitySystemComponent* InASCToGiven, int32_t ApplyLevel /*= 1*/)
{
	if (InAbilitiesToGive.IsEmpty())
	{
		return;
	}

	for (const TSubclassOf<UWarriorGameplayAbility>& Ability : InAbilitiesToGive)
	{
		if(!Ability) continue;

		FGameplayAbilitySpec AbilitySpec(Ability);
		AbilitySpec.SourceObject = InASCToGiven->GetAvatarActor();
		AbilitySpec.Level = ApplyLevel;

		InASCToGiven->GiveAbility(AbilitySpec);
	}
}
