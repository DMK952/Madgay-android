//========= Copyright Valve Corporation, All rights reserved. ============//
//
// Purpose: 
//
// $NoKeywords: $
//=============================================================================//

#ifndef PREDICTED_VIEWMODEL_H
#define PREDICTED_VIEWMODEL_H
#ifdef _WIN32
#pragma once
#endif

#include "predictable_entity.h"
#include "utlvector.h"
#include "baseplayer_shared.h"
#include "shared_classnames.h"

#ifdef CSTRIKE_DLL
#include "weapon_csbase.h" 
    #ifdef CLIENT_DLL
             #include "c_cs_player.h" 
     #endif //client_dll
#endif //cstrike_dll

#if defined( CLIENT_DLL )
#define CPredictedViewModel C_PredictedViewModel
#endif

class CPredictedViewModel : public CBaseViewModel
{
	DECLARE_CLASS( CPredictedViewModel, CBaseViewModel );
public:

	DECLARE_NETWORKCLASS();

	CPredictedViewModel( void );
	virtual ~CPredictedViewModel( void );
							
	virtual void CalcViewModelLag( Vector& origin, QAngle& angles, QAngle& original_angles );
    virtual void AddViewModelBob( CBasePlayer *owner, Vector& eyePosition, QAngle& eyeAngles );

#if defined( CLIENT_DLL ) 
         BobState_t        &GetBobState() { return m_BobState; } 
 #endif //CLIENT_DLL

#if defined( CLIENT_DLL )
	virtual bool ShouldPredict( void )
	{
		if ( GetOwner() && GetOwner() == C_BasePlayer::GetLocalPlayer() )
			return true;

		return BaseClass::ShouldPredict();
	}
#endif

private:
	
#if defined( CLIENT_DLL )

	// This is used to lag the angles.
	CInterpolatedVar<QAngle> m_LagAnglesHistory;
	QAngle m_vLagAngles;

	CPredictedViewModel( const CPredictedViewModel & ); // not defined, not accessible
	#ifdef CSTRIKE_DLL 
     protected: 
         BobState_t                m_BobState;                // view model head bob state
     #endif //cstrike_dll

#endif
};

#endif // PREDICTED_VIEWMODEL_H
