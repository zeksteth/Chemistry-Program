//Types of Equations

  //Capitalization
  void Capitalization (char chemString[]) {
    for (int i = 0; i < strlen(chemString); ++i) {
      chemString[i] = toupper(chemString[i]);
    }
  }

  //Simple conversion
  double simConversion (double input, double x, double y) {
    double output;

    output = input * (x / y);
    return output;
  }
  
  //Chemical conversion
  double Conversion1 (double particles, double inputMoles, double ratio1, double ratio2, double outputMoles) {
    double outputParticles;

    outputParticles = particles * (1.0 / 6.022e23) * (1.0 / inputMoles) * (ratio2 / ratio1) * (outputMoles) * 6.022e23;
    return outputParticles;
  }

  double Conversion2 (double mass, double inputMoles, double ratio1, double ratio2, double outputMoles) {
    double outputMass;
  
    outputMass = mass * (1.0 / inputMoles) * (ratio2 / ratio1) * (outputMoles);
    return outputMass;
  }

  double Conversion3 (double inputMoles, double ratio1, double ratio2) {
    double outputMoles;

    outputMoles = inputMoles * (ratio2 / ratio1);
    return outputMoles;
  }

  //Molarity
  double Molarity1 (double moles, double liters) {
    double molarity;

    molarity = moles / liters;
    return molarity;
  }

  double Molarity2 (double liters, double molarity) {
    double moles;

    moles = liters * molarity;
    return moles;
  }

  double Molarity3 (double moles, double molarity) {
    double liters;

    liters = moles / molarity;
    return liters;
  }

  //Dilution
  double Dilution1 (double Vi, double Mf, double Vf) {
    double Mi;

    Mi = (Mf * Vf) / Vi;
    return Mi;
  }

  double Dilution2 (double Mi, double Mf, double Vf) {
    double Vi;
 
    Vi = (Mf * Vf) / Mi;
    return Vi;
  }
  
  double Dilution3 (double Mi, double Vi, double Vf) {
    double Mf;
  
    Mf = (Mi * Vi) / Vf;
    return Mf;
  }

  double Dilution4 (double Mi, double Vi, double Mf) {
    double Vf;
    
    Vf = (Mi * Vi) / Mf;
    return Vf;
  }
  //Titration
  double Titration1 (double inputLiters, double inputMoles, double ratio1, double ratio2, double outputLiters) {
    double outputMoles;
    double moles;
    double conversion;
    double molarity;

    moles = inputLiters * (inputMoles / 1);
    conversion = Conversion3(moles, ratio1, ratio2);
    molarity = Molarity1(conversion, outputLiters);
    
    return molarity;
  }
    
  //Percent yield
  double Percent1 (double actual, double theoretical) {
    double percent;
  
    percent = (actual / theoretical) * 100;
    return percent;
  }

  double Percent2 (double theoretical, double percent) {
    double actual;

    actual = (percent / 100) * theoretical;
    return actual;
  }

  double Percent3 (double actual, double percent) {
    double theoretical;

    theoretical = actual / (percent / 100);
    return theoretical;
  }