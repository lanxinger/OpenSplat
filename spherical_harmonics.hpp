#ifndef SPHERICAL_HARMONICS_H
#define SPHERICAL_HARMONICS_H

#include <torch/torch.h>
#include "gsplat.hpp"

using namespace torch::autograd;

int degFromSh(int numBases);
torch::Tensor rgb2sh(const torch::Tensor &rgb);

#if defined(USE_HIP) || defined(USE_CUDA)

class SphericalHarmonics : public Function<SphericalHarmonics>{
public:
    static torch::Tensor forward(AutogradContext *ctx, 
            int degreesToUse, 
            torch::Tensor viewDirs, 
            torch::Tensor coeffs);
    static tensor_list backward(AutogradContext *ctx, tensor_list grad_outputs);
};

#endif

class SphericalHarmonicsCPU{
public:
    static torch::Tensor apply(int degreesToUse, 
            torch::Tensor viewDirs, 
            torch::Tensor coeffs);
};

#endif