// Fill out your copyright notice in the Description page of Project Settings.


#include "EOS_Gamemode.h"

#include "OnlineSubsystem.h"
#include "OnlineSubsystemUtils.h"

#include "Interfaces/OnlineIdentityInterface.h"

void AEOS_Gamemode::PostLogin(APlayerController* NewPlayer)
{

Super :: PostLogin(NewPlayer);
	if(NewPlayer)
	{
		FUniqueNetIdRepl	UniqueNetIdRepl;
		if(NewPlayer->IsLocalController())
		{
			ULocalPlayer *LocalPlayerRef = NewPlayer->GetLocalPlayer();
			if(LocalPlayerRef)
			{
				UniqueNetIdRepl = LocalPlayerRef->GetPreferredUniqueNetId();
			}
			else
			{
				UNetConnection *RemoteNetConnectionRef = Cast <UNetConnection>(NewPlayer->Player);
				check(IsValid(RemoteNetConnectionRef));
				UniqueNetIdRepl = RemoteNetConnectionRef->PlayerId;

				
			}
			TSharedPtr<const FUniqueNetId>UniqueNetId = UniqueNetIdRepl.GetUniqueNetId();
			check(UniqueNetId!=nullptr)
			IOnlineSubsystem *SubsystemRef = Online::GetSubsystem(NewPlayer->GetWorld());
			IOnlineSessionPtr SessionRef = SubsystemRef->GetSessionInterface();
			bool bRegistrationSuccess = SessionRef->RegisterPlayer(FName("MainSession"),*UniqueNetId,false);

			if(bRegistrationSuccess)
			{
				UE_LOG(LogTemp,Warning,TEXT("Registration Successful"));  
			}
		}
	}
	
}
