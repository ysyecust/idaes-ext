#include "props_sp.h"
#include<iostream>
#include<stdlib.h>

prop_memo_table22 memo_table_internal_energy_sp;
prop_memo_table22 memo_table_enthalpy_sp;
prop_memo_table22 memo_table_gibbs_sp;
prop_memo_table22 memo_table_helmholtz_sp;
prop_memo_table22 memo_table_isochoric_heat_capacity_sp;
prop_memo_table22 memo_table_isobaric_heat_capacity_sp;
prop_memo_table22 memo_table_speed_of_sound_sp;
prop_memo_table22 memo_table_specific_volume_sp;
prop_memo_table22 memo_table_temperature_sp;
prop_memo_table22 memo_table_vapor_fraction_sp;
prop_memo_table22 memo_table_viscosity_sp;
prop_memo_table22 memo_table_thermal_conductivity_sp;
prop_memo_table22 memo_table_surface_tension_sp;

prop_memo_table22 memo_table_entropy_liq_sp;
prop_memo_table22 memo_table_internal_energy_liq_sp;
prop_memo_table22 memo_table_enthalpy_liq_sp;
prop_memo_table22 memo_table_gibbs_liq_sp;
prop_memo_table22 memo_table_helmholtz_liq_sp;
prop_memo_table22 memo_table_isochoric_heat_capacity_liq_sp;
prop_memo_table22 memo_table_isobaric_heat_capacity_liq_sp;
prop_memo_table22 memo_table_speed_of_sound_liq_sp;
prop_memo_table22 memo_table_specific_volume_liq_sp;
prop_memo_table22 memo_table_viscosity_liq_sp;
prop_memo_table22 memo_table_thermal_conductivity_liq_sp;
prop_memo_table22 memo_table_surface_tension_liq_sp;

prop_memo_table22 memo_table_entropy_vap_sp;
prop_memo_table22 memo_table_internal_energy_vap_sp;
prop_memo_table22 memo_table_enthalpy_vap_sp;
prop_memo_table22 memo_table_gibbs_vap_sp;
prop_memo_table22 memo_table_helmholtz_vap_sp;
prop_memo_table22 memo_table_isochoric_heat_capacity_vap_sp;
prop_memo_table22 memo_table_isobaric_heat_capacity_vap_sp;
prop_memo_table22 memo_table_speed_of_sound_vap_sp;
prop_memo_table22 memo_table_specific_volume_vap_sp;
prop_memo_table22 memo_table_viscosity_vap_sp;
prop_memo_table22 memo_table_thermal_conductivity_vap_sp;
prop_memo_table22 memo_table_surface_tension_vap_sp;

//T
void temperature_sp(uint comp, double s, double p, f22_struct *out){ 
    f22_struct tau_vec = memo2_tau_sp(comp, s, p);
    out->f = cdata[comp].T_star/tau_vec.f;
    out->f_1 = -cdata[comp].T_star/tau_vec.f/tau_vec.f*tau_vec.f_1;
    out->f_2 = -cdata[comp].T_star/tau_vec.f/tau_vec.f*tau_vec.f_2;
    out->f_11 = 2*cdata[comp].T_star/tau_vec.f/tau_vec.f/tau_vec.f*tau_vec.f_1*tau_vec.f_1 - cdata[comp].T_star/tau_vec.f/tau_vec.f*tau_vec.f_11;
    out->f_12 = 2*cdata[comp].T_star/tau_vec.f/tau_vec.f/tau_vec.f*tau_vec.f_1*tau_vec.f_2 - cdata[comp].T_star/tau_vec.f/tau_vec.f*tau_vec.f_12;
    out->f_22 = 2*cdata[comp].T_star/tau_vec.f/tau_vec.f/tau_vec.f*tau_vec.f_2*tau_vec.f_2 - cdata[comp].T_star/tau_vec.f/tau_vec.f*tau_vec.f_22;
}
MEMO2_FUNCTION(memo2_temperature_sp, temperature_sp, memo_table_temperature_sp)

//vapor_fraction
void vapor_fraction_sp(uint comp, double s, double p, f22_struct *out){ 
    f22_struct vf_vec = memo2_vf_sp(comp, s, p);
    out->f = vf_vec.f;
    out->f_1 = vf_vec.f_1;
    out->f_2 = vf_vec.f_2;
    out->f_11 = vf_vec.f_11;
    out->f_12 = vf_vec.f_12;
    out->f_22 = vf_vec.f_22;
}
MEMO2_FUNCTION(memo2_vapor_fraction_sp, vapor_fraction_sp, memo_table_vapor_fraction_sp)


//s
PROP_SP_SINGLE_PHASE(entropy_vap_sp, memo2_entropy, memo2_delta_vapor)
PROP_SP_SINGLE_PHASE(entropy_liq_sp, memo2_entropy, memo2_delta_liquid)
MEMO2_FUNCTION(memo2_entropy_vap_sp, entropy_vap_sp, memo_table_entropy_vap_sp)
MEMO2_FUNCTION(memo2_entropy_liq_sp, entropy_liq_sp, memo_table_entropy_liq_sp)

//u
PROP_SP_SINGLE_PHASE(internal_energy_vap_sp, memo2_internal_energy, memo2_delta_vapor)
PROP_SP_SINGLE_PHASE(internal_energy_liq_sp, memo2_internal_energy, memo2_delta_liquid)
PROP_SP_GENERAL(internal_energy_sp, internal_energy_liq_sp, internal_energy_vap_sp)
MEMO2_FUNCTION(memo2_internal_energy_sp, internal_energy_sp, memo_table_internal_energy_sp)
MEMO2_FUNCTION(memo2_internal_energy_vap_sp, internal_energy_vap_sp, memo_table_internal_energy_vap_sp)
MEMO2_FUNCTION(memo2_internal_energy_liq_sp, internal_energy_liq_sp, memo_table_internal_energy_liq_sp)

//h
PROP_SP_SINGLE_PHASE(enthalpy_vap_sp, memo2_enthalpy, memo2_delta_vapor)
PROP_SP_SINGLE_PHASE(enthalpy_liq_sp, memo2_enthalpy, memo2_delta_liquid)
PROP_SP_GENERAL(enthalpy_sp, enthalpy_liq_sp, enthalpy_vap_sp)
MEMO2_FUNCTION(memo2_enthalpy_sp, enthalpy_sp, memo_table_enthalpy_sp)
MEMO2_FUNCTION(memo2_enthalpy_vap_sp, enthalpy_vap_sp, memo_table_enthalpy_vap_sp)
MEMO2_FUNCTION(memo2_enthalpy_liq_sp, enthalpy_liq_sp, memo_table_enthalpy_liq_sp)

//g
PROP_SP_SINGLE_PHASE(gibbs_vap_sp, memo2_gibbs, memo2_delta_vapor)
PROP_SP_SINGLE_PHASE(gibbs_liq_sp, memo2_gibbs, memo2_delta_liquid)
PROP_SP_GENERAL(gibbs_sp, gibbs_liq_sp, gibbs_vap_sp)
MEMO2_FUNCTION(memo2_gibbs_sp, gibbs_sp, memo_table_gibbs_sp)
MEMO2_FUNCTION(memo2_gibbs_vap_sp, gibbs_vap_sp, memo_table_gibbs_vap_sp)
MEMO2_FUNCTION(memo2_gibbs_liq_sp, gibbs_liq_sp, memo_table_gibbs_liq_sp)

//f
PROP_SP_SINGLE_PHASE(helmholtz_vap_sp, memo2_helmholtz, memo2_delta_vapor)
PROP_SP_SINGLE_PHASE(helmholtz_liq_sp, memo2_helmholtz, memo2_delta_liquid)
PROP_SP_GENERAL(helmholtz_sp, helmholtz_liq_sp, helmholtz_vap_sp)
MEMO2_FUNCTION(memo2_helmholtz_sp, helmholtz_sp, memo_table_helmholtz_sp)
MEMO2_FUNCTION(memo2_helmholtz_vap_sp, helmholtz_vap_sp, memo_table_helmholtz_vap_sp)
MEMO2_FUNCTION(memo2_helmholtz_liq_sp, helmholtz_liq_sp, memo_table_helmholtz_liq_sp)

//cv
PROP_SP_SINGLE_PHASE(isochoric_heat_capacity_vap_sp, memo2_isochoric_heat_capacity, memo2_delta_vapor)
PROP_SP_SINGLE_PHASE(isochoric_heat_capacity_liq_sp, memo2_isochoric_heat_capacity, memo2_delta_liquid)
PROP_SP_GENERAL(isochoric_heat_capacity_sp, isochoric_heat_capacity_liq_sp, isochoric_heat_capacity_vap_sp)
MEMO2_FUNCTION(memo2_isochoric_heat_capacity_sp, isochoric_heat_capacity_sp, memo_table_isochoric_heat_capacity_sp)
MEMO2_FUNCTION(memo2_isochoric_heat_capacity_vap_sp, isochoric_heat_capacity_vap_sp, memo_table_isochoric_heat_capacity_vap_sp)
MEMO2_FUNCTION(memo2_isochoric_heat_capacity_liq_sp, isochoric_heat_capacity_liq_sp, memo_table_isochoric_heat_capacity_liq_sp)

//cp
PROP_SP_SINGLE_PHASE(isobaric_heat_capacity_vap_sp, memo2_isobaric_heat_capacity, memo2_delta_vapor)
PROP_SP_SINGLE_PHASE(isobaric_heat_capacity_liq_sp, memo2_isobaric_heat_capacity, memo2_delta_liquid)
PROP_SP_GENERAL(isobaric_heat_capacity_sp, isobaric_heat_capacity_liq_sp, isobaric_heat_capacity_vap_sp)
MEMO2_FUNCTION(memo2_isobaric_heat_capacity_sp, isobaric_heat_capacity_sp, memo_table_isobaric_heat_capacity_sp)
MEMO2_FUNCTION(memo2_isobaric_heat_capacity_vap_sp, isobaric_heat_capacity_vap_sp, memo_table_isobaric_heat_capacity_vap_sp)
MEMO2_FUNCTION(memo2_isobaric_heat_capacity_liq_sp, isobaric_heat_capacity_liq_sp, memo_table_isobaric_heat_capacity_liq_sp)

//w (doesn't really mean much in the two phase region, so use with care)
PROP_SP_SINGLE_PHASE(speed_of_sound_vap_sp, memo2_speed_of_sound, memo2_delta_vapor)
PROP_SP_SINGLE_PHASE(speed_of_sound_liq_sp, memo2_speed_of_sound, memo2_delta_liquid)
PROP_SP_GENERAL(speed_of_sound_sp, speed_of_sound_liq_sp, speed_of_sound_vap_sp)
MEMO2_FUNCTION(memo2_speed_of_sound_sp, speed_of_sound_sp, memo_table_speed_of_sound_sp)
MEMO2_FUNCTION(memo2_speed_of_sound_vap_sp, speed_of_sound_vap_sp, memo_table_speed_of_sound_vap_sp)
MEMO2_FUNCTION(memo2_speed_of_sound_liq_sp, speed_of_sound_liq_sp, memo_table_speed_of_sound_liq_sp)

//v
PROP_SP_SINGLE_PHASE(specific_volume_vap_sp, memo2_specific_volume, memo2_delta_vapor)
PROP_SP_SINGLE_PHASE(specific_volume_liq_sp, memo2_specific_volume, memo2_delta_liquid)
PROP_SP_GENERAL(specific_volume_sp, specific_volume_liq_sp, specific_volume_vap_sp)
MEMO2_FUNCTION(memo2_specific_volume_sp, specific_volume_sp, memo_table_specific_volume_sp)
MEMO2_FUNCTION(memo2_specific_volume_vap_sp, specific_volume_vap_sp, memo_table_specific_volume_vap_sp)
MEMO2_FUNCTION(memo2_specific_volume_liq_sp, specific_volume_liq_sp, memo_table_specific_volume_liq_sp)

//viscosity
PROP_SP_SINGLE_PHASE(viscosity_vap_sp, memo2_viscosity, memo2_delta_vapor)
PROP_SP_SINGLE_PHASE(viscosity_liq_sp, memo2_viscosity, memo2_delta_liquid)
PROP_SP_GENERAL(viscosity_sp, viscosity_liq_sp, viscosity_vap_sp)
MEMO2_FUNCTION(memo2_viscosity_sp, viscosity_sp, memo_table_viscosity_sp)
MEMO2_FUNCTION(memo2_viscosity_vap_sp, viscosity_vap_sp, memo_table_viscosity_vap_sp)
MEMO2_FUNCTION(memo2_viscosity_liq_sp, viscosity_liq_sp, memo_table_viscosity_liq_sp)

//thermal conductivity
PROP_SP_SINGLE_PHASE(thermal_conductivity_vap_sp, memo2_thermal_conductivity, memo2_delta_vapor)
PROP_SP_SINGLE_PHASE(thermal_conductivity_liq_sp, memo2_thermal_conductivity, memo2_delta_liquid)
PROP_SP_GENERAL(thermal_conductivity_sp, thermal_conductivity_liq_sp, thermal_conductivity_vap_sp)
MEMO2_FUNCTION(memo2_thermal_conductivity_sp, thermal_conductivity_sp, memo_table_thermal_conductivity_sp)
MEMO2_FUNCTION(memo2_thermal_conductivity_vap_sp, thermal_conductivity_vap_sp, memo_table_thermal_conductivity_vap_sp)
MEMO2_FUNCTION(memo2_thermal_conductivity_liq_sp, thermal_conductivity_liq_sp, memo_table_thermal_conductivity_liq_sp)

//surface tension
PROP_SP_SINGLE_PHASE(surface_tension_vap_sp, memo2_surface_tension, memo2_delta_vapor)
PROP_SP_SINGLE_PHASE(surface_tension_liq_sp, memo2_surface_tension, memo2_delta_liquid)
PROP_SP_GENERAL(surface_tension_sp, surface_tension_liq_sp, surface_tension_vap_sp)
MEMO2_FUNCTION(memo2_surface_tension_sp, surface_tension_sp, memo_table_surface_tension_sp)
MEMO2_FUNCTION(memo2_surface_tension_vap_sp, surface_tension_vap_sp, memo_table_surface_tension_vap_sp)
MEMO2_FUNCTION(memo2_surface_tension_liq_sp, surface_tension_liq_sp, memo_table_surface_tension_liq_sp)