 // Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Interfaces/OnlineSessionInterface.h"
#include "EOS_GameInstance.generated.h"

/**
 * 
 */
UCLASS()
class ESCAPE_THE_MAZE_API UEOS_GameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
    	
	UFUNCTION(BlueprintCallable, Category="EOS Functions")
	void LoginWithEOS(FString ID, FString Token, FString LoginType);

	
	void LoginWithEOS_Return(int32 LocalUserNum, bool bWasSuccess, const FUniqueNetId& UserId, const FString& Error );



	UFUNCTION(BlueprintCallable, Category="EOS Functions")
	void CreateEOSSession(bool bIsDedicatedServer, bool IsLanServer, int32 NumberOfPubliConnections);

	
	void OnSessionCreateComplete(FName Session, bool bWasSession);
	

	UFUNCTION(BlueprintCallable, BlueprintPure,Category="EOS Functions")
    	FString GetPlayerUsername( );
    
    
    	
    	UFUNCTION(BlueprintCallable, BlueprintPure,Category="EOS Functions")
    		bool IsPalyerLoggedIn( );
    
    	
    
    
  



    
    
    	UFUNCTION(BlueprintCallable, Category="EOS Functions")
    
    	void FindSessionAndJoin();
    
    	//UFUNCTION(BlueprintCallable, Category="EOS Functions")
    
    	//void JoinSession();
    
    
    	UFUNCTION(BlueprintCallable, Category="EOS Functions")
    	void DestroySession();
    
    	
    
    	TSharedPtr<FOnlineSessionSearch> SessionSearch;
    
    
	// ReSharper disable once UnrealHeaderToolError
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="EOS Variables")
    	FString OpenLevelText;
    
    
    
    
    
    	
    	
    	
    	void OnDestroyCreateComplete(FName Session, bool bWasSession);
    
    
    	void OnFindSessionCompleted(bool bWasSucces);
    
    	
	void OnJoinSessionCompleted(FName SessionName, EOnJoinSessionCompleteResult :: Type Result);
    	
	
};
