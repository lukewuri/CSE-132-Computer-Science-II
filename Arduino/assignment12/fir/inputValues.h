// Two arrays, input1 and input2, with noisy sine waves to filter.
// Created using FIRExample.m

#define NUM_SAMPS 125
// Noisy sine wave, f = 20
int input1[NUM_SAMPS] = {
  -1424,
  -3424,
  4352,
  6544,
  3152,
  11696,
  12080,
  7920,
  8480,
  6880,
  4208,
  5392,
  -896,
  6128,
  -3456,
  -4448,
  -2816,
  -7216,
  -8368,
  -10896,
  -6832,
  -11296,
  -3264,
  1376,
  -4304,
  2816,
  6144,  // 27
  -1280,
  880,
  8784,
  6480,
  10432,
  10720,
  9744,
  10544,
  7008,
  6912,
  -2912,
  -1088,
  -3536,
  -10064,
  -5472,
  -10880,
  -3408,
  -10816,
  -6064,
  -6192,
  -8624,
  -11056,
  -2224,
  -3312,
  4048,
  5616,
  11152,
  8848,
  5680,
  9424,
  4736,
  7344,
  6160,
  4816,
  1968,
  4608,
  -7168,
  -1616,
  -1888,
  -3920,
  -5520,
  -7920,
  -5952,
  -5920,
  -7760,
  -6848,
  -4912,
  -6864,
  -768,
  2432,
  4976,
  10336,
  5760,
  9840,
  10800,
  11136,
  4160,
  7008,
  5600,
  -288,
  -1408,
  2512,
  -3440,
  -3536,
  -6016,
  -9488,
  -9888,
  -6720,
  -10896,
  -4352,
  -3744,
  -6640,
  -2912,
  -3888,
  -5184,
  7184,
  3904,
  7984,
  8560,
  8240,
  4752,
  4304,
  5088,
  928,
  -448,
  5856,
  -848,
  -7008,
  -4944,
  -10016,
  -11840,
  -8896,
  -5056,
  -7376,
  -4768,
  -9440,
  -5456,
  -2896
};

// Noisy sine wave, f = 20
int input2[NUM_SAMPS] = {
  -1424,
  -3424,
  4352,
  6544,
  3152,
  11696,
  12080,
  7920,
  8480,
  6880,
  4208,
  5392,
  -896,
  6128,
  -3456,
  -4448,
  -2816,
  -7216,
  -8368,
  -10896,
  -6832,
  -11296,
  -3264,
  1376,
  -4304,
  2816,
  6144,
  -1280,
  880,
  8784,
  6480,
  10432,
  10720,
  9744,
  10544,
  7008,
  6912,
  -2912,
  -1088,
  -3536,
  -10064,
  -5472,
  -10880,
  -3408,
  -10816,
  -6064,
  -6192,
  -8624,
  -11056,
  -2224,
  -3312,
  4048,
  5616,
  11152,
  8848,
  5680,
  9424,
  4736,
  7344,
  6160,
  4816,
  1968,
  4608,
  -7168,
  -1616,
  -1888,
  -3920,
  -5520,
  -7920,
  -5952,
  -5920,
  -7760,
  -6848,
  -4912,
  -6864,
  -768,
  2432,
  4976,
  10336,
  5760,
  9840,
  10800,
  11136,
  4160,
  7008,
  5600,
  -288,
  -1408,
  2512,
  -3440,
  -3536,
  -6016,
  -9488,
  -9888,
  -6720,
  -10896,
  -4352,
  -3744,
  -6640,
  -2912,
  -3888,
  -5184,
  7184,
  3904,
  7984,
  8560,
  8240,
  4752,
  4304,
  5088,
  928,
  -448,
  5856,
  -848,
  -7008,
  -4944,
  -10016,
  -11840,
  -8896,
  -5056,
  -7376,
  -4768,
  -9440,
  -5456,
  -2896
};
