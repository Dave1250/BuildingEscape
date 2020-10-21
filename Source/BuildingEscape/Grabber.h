// Copyright

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "Grabber.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabber();

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void FindPhysicsHandle();
	void SetupInputComponent();
	void Grab();
	void Relase();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:
	float Reach = 130.f;

	UPhysicsHandleComponent* PhysicsHandle = nullptr;
	UInputComponent* InputComponent = nullptr;

	//Return 1st actor in reach with physics body
	FHitResult GetFirstPhysicsBodyInReach() const;

	//Return the Line Trace End
	FVector GetPlayerReach() const;

	//Get Player Position in the world 
	FVector GetPlayerPosition() const;
};
