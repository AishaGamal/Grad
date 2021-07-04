

const int ReadingsCount = 2;
const float irRaws[] {200,47000};
const float redRaws[] {30,37200};
const float bloodSugerLevel[] {0,90};

float prepareBloodSugre (uint16_t ir, uint16_t red)
{
  float blood = 0;

  int irIndex = -1;
  int redIndex = -1;
  int i;
  for (i=0; i<ReadingsCount-1; i++)
  {
    if (ir <=irRaws[i+1] && ir >= irRaws[i])
    {
      irIndex = i;
      if ( (ir-irRaws[i]) > (irRaws[i+1]-ir))
      {
        irIndex = i+1;
      }
      
    }
    if (red <=redRaws[i+1] && red >= redRaws[i])
    {
      redIndex = i;
      if ( (red-redRaws[i]) > (redRaws[i+1]-red))
      {
        redIndex = i+1;
      }
    }
  }

  if (irIndex == redIndex)
  {
    blood = bloodSugerLevel[irIndex];
  }
  else
  {
    blood = (bloodSugerLevel[irIndex]+bloodSugerLevel[redIndex]) / 2.0;
  }

  return blood;
}
