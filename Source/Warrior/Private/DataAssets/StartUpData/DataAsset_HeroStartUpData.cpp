// Fill out your copyright notice in the Description page of Project Settings.


#include "DataAssets/StartUpData/DataAsset_HeroStartUpData.h"
#include "AbilitySystem/WarriorAbilitySystemComponent.h"
#include "AbilitySystem/Abilities/WarriorHeroGameplayAbility.h"

void UDataAsset_HeroStartUpData::GivenToAbilitySystemComponent(UWarriorAbilitySystemComponent* InASCToGiven, int32_t ApplyLevel /*= 1*/)
{
	Super::GivenToAbilitySystemComponent(InASCToGiven, ApplyLevel);

	for (const FWarriorHeroAbilitySet& AbilitySet : HeroStartupAbilitySets)
	{
		if(!AbilitySet.IsValid()) continue;

		FGameplayAbilitySpec AbilitySpec(AbilitySet.AbilityToGrant);
		AbilitySpec.SourceObject = InASCToGiven->GetAvatarActor();
		AbilitySpec.Level = ApplyLevel;
		AbilitySpec.DynamicAbilityTags.AddTag(AbilitySet.InputTag);

		InASCToGiven->GiveAbility(AbilitySpec);
	}
}
