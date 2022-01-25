#pragma once
#include "../Logic/matrix_math.h"

typedef struct kalman KalmanFilter;
typedef struct dimensions Matrix_Dimensions;

//DECLARATIONS

/**
 * @brief 
 * 
 * @param initialState Takes an array of Initial State Values
 * @param stateTransMatrix Takes the address of a 2D array of State Trans Matrix values.
 * @param inputMatrix Takes the address of a 2D array of Input Matrix values.
 * @param stateVars_n Number of state variables
 * @param inputs_p Number of Inputs
 * @param outputs_m Number of Outputs
 * @return ** KalmanFilter* 
 */
KalmanFilter* KalmanInit(double* initialState, double* stateTransMatrix, double* inputMatrix, 
    int stateVars_n, int inputs_p, int outputs_m);

    
/**
 * @brief 
 * 
 * @param k_filter 
 * @return ** KalmanFilter* 
 */
KalmanFilter* kalman_filter(KalmanFilter *k_filter);


//Structs
struct kalman {
    
    Matrix *state_trans_matrix; //State Transition Matrix (F)
    Matrix *updatedStateEstimate; // Initial State Est. Vector (x) & Updated State Estimate Vector (x+) 
    Matrix *updatedCovariance; // Initial Covariance Matrix (P) & Updated Covariance Matrix (P+) 
    
    Matrix *input_matrix; //Input Matrix (B)
    Matrix *input_vector; //Input Vector (u)  /* Incoming measurements */
    
    Matrix *measurement_matrix; //Measurement Matrix (H)

    Matrix *process_model_noise_matrix; // Process Model Noise Matrix (L)
    Matrix *process_model_noise_vector; // Process Model Noise Vector (w)
    
    Matrix *measurement_model_noise_matrix; // Measurement Model Noise Matrix (M)
    Matrix *measurement_noise_vector; // Measurement Model Noise Vector (v)

    Matrix *innovation; // Innovation Matrix (y)
    Matrix *innovationCovariance; // Innovation Covariance Matrix (S)
    Matrix *kalmanGainMatrix; // Kalman Gain Matrix (K)

    Matrix *expectedCovariance;  // Expected Covariance Matrix (P-)
    Matrix *expectedStateEstimate; // Expected State Estimate Vector (x-)

    Matrix *autoCorrelatoinQ; // Auto Correlation Matrix 1 (Q)
    Matrix *autoCorrelatoinR; // Auto Correlation Matrix 2 (R)

    // This one might end up being temporary
    Matrix *sensorValues;

};
