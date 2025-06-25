#include "AbilitySystem/Data/DA_TED_CharacterClassInfo.h"

FCharacterClassDefaultInfo UDA_TED_CharacterClassInfo::GetClassDefaultInfo(ECharacterClass CharacterClass)
{
    if (!CharacterClassInformation.Contains(CharacterClass))
    {
        return FCharacterClassDefaultInfo();
    }

    return CharacterClassInformation.FindChecked(CharacterClass);
}

FEnemyClassDefaultInfo UDA_TED_CharacterClassInfo::GetEnemyClassDefaultInfo(EEnemyClass EnemyClass)
{
    if (!EnemyClassInformation.Contains(EnemyClass))
    {
        return FEnemyClassDefaultInfo();
    }

    return EnemyClassInformation.FindChecked(EnemyClass);
}
