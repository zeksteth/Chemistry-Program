#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "chemistry1.c"

/* 
To do list
	1: finish current set of equations
	2: add more stuff from notes
	3: add in pointers 
	4: create printf statements or functions that show the process of the different equations in detail.
*/

int main(void){
  int x;
  int y;
  int userNum;
  userNum = 0;

  //Starting prompt
  printf("Enter number for type of equation:\n");
  printf("0 = Equation formulas\n");
  printf("1 = Simple conversion\n");
  printf("2 = Chemical conversion\n");
  printf("3 = Molarity\n");
  printf("4 = Dilution\n");
  printf("5 = Titration\n");
  printf("6 = Percent yield\n");
  printf("7 = Pressure\n");
  printf("8 = Dalton's Law of Partial Pressures\n");
  printf("9 = Maxwell-Boltzmann distribution\n");
  printf("10 = Most Probable Speed\n");
  printf("11 = van der Waals Equation\n");
  scanf("%d", &x);
  
//Equation formulas
  switch (x){
    case 0:
    while (userNum == 0){
      printf("1 = Conversion Flow Chart\n");
      printf("2 = Molarity\n");
      printf("3 = Dilution\n");
      printf("4 = Percent Yield\n");
      printf("5 = Pressure Equations\n");
      printf("6 = Dalton's Law of Partial Pressures\n");
      printf("7 = Maxwell-Boltzmann distribution\n");
      printf("8 = Most Probable Speed\n");
      printf("9 = van der Waals Equation\n");
      printf("10 = van der Waals constants table\n");
  
      scanf("%d", &y);

      switch (y){
        case 1:
          printf("Mass Given --> (1.00 mol/ Molar Mass of Input) --> Balanced Equation Ratio --> Molar Mass of Output --> Mass Desired\n");
          break;
        case 2:
          printf("Molarity = (Moles of Solute) / (Volume of Solution) | M = n / v\n");
          break;
        case 3:
          printf("Initial Molarity * Initial Volume = Final Molarity * Final Volume | Mi * Vi = Mf * Vf\n");
          break;
        case 4:
          printf("Percent Yield = (Actual Yield / Theoretical Yield) * 100\n");
          break;
        case 5:
          printf("Pressure = Force / Area | P = F / A\n");
          printf("Pressure * Volume = Moles * R(constant) * Temperature | PV = nRT\n");
          break;
        case 6:
          printf("Total Pressue = Total Moles * [(R(constant) * Temperature) / Volume] | P = n(RT/V)\n");
          printf("Mole Fraction = Initial Moles / Total Moles | X(i) = n(i)/n(total)\n");
          printf("Initial Pressure = Mole Fraction * Total Pressure | P(i) = X(i)*P(total)\n");
          break;
        case 7:
          printf("[N(v)/N(total)] = 4pi(M/2piRT)^(3/2)(v^2)(e^(-M(v^2)/2RT))\n");
          printf("N(v) =  # of molecules moving with speeds between v and delta v (change in v)\n");
          printf("N(total) = The total # of molecules\n");
          printf("M = Molar mass of gas\n");
          printf("R = Gas constant\n");
          printf("T = Temperature\n");
          printf("v = Most probable speed\n");
          break;
        case 8:
          printf("v(mp) = sqrt(2RT/M)\n");
          printf("This is the v value for the Maxwell-Boltzmann distribution\n");
          break;
        case 9:
          printf("[P+(a(n^2)/(V^2))](V-nb) = nRT\n");
          printf("P = [(nRT)/(V-nb)]-[a(n^2)/(V^2)]\n");
          printf("P = Pressure\n");
          printf("n = Moles of gas");
          printf("R = Gas constant\n");
          printf("T = Temperature\n");
          printf("V = Volume\n");
          printf("a & b = van der Waals constants. See van der Waals constants table\n");
          break;
        case 10:
          printf("Gas                   |a (atm(L^2)(mol^-2))  |b (L(mol^-1))|\n");
          printf("Ammonia(NH3)          |4.120                 |0.03207      |\n");
          printf("Argon(Ar)             |1.345                 |0.03219      |\n");
          printf("Carbon dioxide(CO2),  |3.592                 |0.04267      |\n");
          printf("Helium(He),           |0.034                 |0.0237       |\n");
          printf("Hydrogen(H2),         |0.2444                |0.02681      |\n");
          printf("Hydrogen fluoride(Hf) |9.433                 |0.0739       |\n");
          printf("Methane(CH4)          |2.253                 |0.04278      |\n");
          printf("Nitrogen(N2)          |1.390                 |0.03913      |\n");
          printf("Oxygen(O2)            |1.360                 |0.03183      |\n");
          printf("Sulfur dioxide(SO2)   |6.714                 |0.05636      |\n");
          printf("Water(H2O)            |5.464                 |0.03049      |\n");
          break;
      }
      printf("Need another equation? yes = 0, no = 1\n");
      scanf("%d", &userNum);
    }
      break;

//Simple conversion
    case 1:
      double inputUnit;
      double conversion1;
      double conversion2;
      char conIn[20];
      char conOut[20];

      printf("Enter the input and ratio. (input * (x / y) | ex: 2.35 * (1 / 1000)). Enter as (a, b, c):\n");
      scanf("%lf, %lf, %lf", &inputUnit, &conversion1, &conversion2);

      printf("Enter labels for input and for what you are converting to. Enter as (first-label second-label):\n");
      scanf("%s %s", conIn, conOut);

      printf("%lf %s converts to %lf %s\n", inputUnit, conIn, simConversion(inputUnit, conversion1, conversion2), conOut);
      break;

//Chemical conversion
    case 2:
      double particles;
      double mass;
      double inputMoles;
      double ratio1;
      double ratio2;
      double outputMoles;
      char chemicalInput[20];
      char chemicalOutput[20];

      printf("What label are you given? (1 = Particles, 2 = Grams, 3 = Moles)\n");
      scanf("%d", &y);

      switch (y){
        case 1:
          printf("Enter particles, molar mass of input, moles of input, moles of output, and molar mass of output. Enter as (a, b, c, d, e):\n");
          scanf("%lf, %lf, %lf, %lf, %lf", &particles, &inputMoles, &ratio1, &ratio2, &outputMoles);
      
          printf("Enter the chemical input and output. Enter as (input, output):\n");
          scanf("%s, %s", chemicalInput, chemicalOutput);
          Capitalization(chemicalInput);
	  Capitalization(chemicalOutput);

          printf("%lf particles of %s produces (or needs) %lf particles of %s\n", particles, chemicalInput, Conversion1(particles, inputMoles, ratio1, ratio2, outputMoles), chemicalOutput);
          break;
        case 2:
          printf("Enter input mass, molar mass, moles of input, moles of output, and output molar mass. Enter as (a, b, c, d, e):\n" );
          scanf("%lf, %lf, %lf, %lf, %lf", &mass, &inputMoles, &ratio1, &ratio2, &outputMoles);

          printf("Enter the chemical input and output:\n");
          scanf("%s %s", chemicalInput, chemicalOutput);
	  Capitalization(chemicalInput);
	  Capitalization(chemicalOutput);
    
          printf("%lf grams of %s produces (or needs) %lf grams of %s\n", mass, chemicalInput, Conversion2(mass, inputMoles, ratio1, ratio2, outputMoles), chemicalOutput);
          break;
        case 3:
          printf("Enter input moles, moles of input, and moles of output. Enter as (a, b, c):\n");
          scanf("%lf, %lf, %lf", &inputMoles, &ratio1, &ratio2);

          printf("Enter the chemical input and output:\n");
          scanf("%s %s", chemicalInput, chemicalOutput);
	  Capitalization(chemicalInput);
	  Capitalization(chemicalOutput);

          printf("%lf moles of %s produces (or needs) %lf moles of %s\n", inputMoles, chemicalInput, Conversion3(inputMoles, ratio1, ratio2), chemicalOutput);
          break;
      }
      break;

//Molarity
    case 3:
      double molesSolute;
      double litersSolution;
      double molarity;

      printf("What are you trying to find? (1 = Molarity, 2 = Moles of Solute, 3 = Volume of Solution)\n");
      scanf("%d", &y);

      switch (y){
        case 1:
          printf("Enter moles of solute and volume of solution. Enter as (a, b):\n");
          scanf("%lf, %lf", &molesSolute, &litersSolution);
      
          printf("The molarity is %lf M\n", Molarity1(molesSolute, litersSolution));
          break;
        case 2:
          printf("Enter volume of solution and molarity. Enter as (a, b):\n");
          scanf("%lf, %lf", &litersSolution, &molarity);
        
          printf("The moles of solute is %lf moles\n", Molarity2(litersSolution, molarity));
          break;
        case 3:
          printf("Enter moles of solute and molarity. Enter as (a, b):\n");
          scanf("%lf, %lf", &molesSolute, &molarity);

          printf("The volume of solution is %lf L\n", Molarity3(molesSolute, molarity));
          break;
      }
      break;

//Dilution
    case 4:
      double Mi;
      double Vi;
      double Mf;
      double Vf;

      printf("What are you trying to find? (1 = Mi, 2 = Vi, 3 = Mf, 4 = Vf):\n");
      scanf("%d", &y);
   
      switch (y){
        case 1:
          printf("Enter initial volume, final molarity, and final volume. Enter as (a, b, c):\n");
          scanf("%lf, %lf, %lf", &Vi, &Mf, &Vf);

          printf("The inital molarity is %lf M\n", Dilution1(Vi, Mf, Vf));
          break;
        case2:
          printf("Enter initial molarity, final molarity, and final volume. Enter as (a, b, c):\n");
          scanf("%lf, %lf, %lf", &Mi, &Mf, &Vf);

          printf("The initial volume is %lf L\n", Dilution2(Mi, Mf, Vf));
          break;
        case 3:
          printf("Enter initial molarity, initial volume, and final volume. Enter as (a, b, c):\n");
          scanf("%lf, %lf, %lf", &Mi, &Vi, &Vf);

          printf("The final molarity is %lf M\n", Dilution3(Mi, Vi, Vf));
          break;
        case 4:
          printf("Enter initial molarity, initial volume, and final molarity. Enter as (a, b, c):\n");
          scanf("%lf, %lf, %lf", &Mi, &Vi, &Mf);

          printf("The final volume is %lf L\n", Dilution4(Mi, Vi, Mf));
          break;
      }
      break;

//Titration
    case 5:
      printf("What are you trying to find? (1 = Molarity)\n");
      scanf("%d", &y);

      switch(y){
        case 1:
	  double inLiters;
	  double inMoles;
	  double outLiters;
	  int r1;	
	  int r2;
	  char chemIn[20];
	  char chemOut[20];

	  printf("Enter input liters, input moles, moles of input, moles of output, and output liters. Enter as (a, b, c, d, e):\n");
	  scanf("%lf, %lf, %d, %d, %lf", &inLiters, &inMoles, &r1, &r2, &outLiters);

          printf("Enter the chemical input and output:\n");
          scanf("%s %s", chemIn, chemOut);
          Capitalization(chemIn);
          Capitalization(chemOut);

	  printf("%lf liters of %s titrates to %lf M of %s\n", inLiters, chemIn, Titration1(inLiters, inMoles, r1, r2, outLiters), chemOut);
	  break;
      }
      break;

//Percent yield
    case 6:
      double actual;
      double theoretical;
      double percent;

      printf("What are you trying to find? (1 = percent yield, 2 = actual yield, 3 = theoretical yield)\n");
      scanf("%d", &y);

      switch (y){
        case 1:
          printf("Enter actual yield and theoretical yield. Enter as (a, b):\n");
          scanf("%lf, %lf", &actual, &theoretical);

          printf("The percent yield is %lf percent\n", Percent1(actual, theoretical));
          break;
        case 2:
          printf("Enter theoretical yield and percent yield. Enter as (a, b):\n");
          scanf("%lf, %lf", &theoretical, &percent);
 
          printf("The actual yield is %lf\n", Percent2(theoretical, percent));
          break;
        case 3:
          printf("Enter actual yield and percent yield. Enter as (a, b):\n");
          scanf("%lf, %lf", &actual, &percent);

          printf("The theoretical yield is %lf\n", Percent3(actual, percent));
          break;
      }
      break;

//Pressure
    case 7:
      break;

//Dalton's Law of Partial Pressures
    case 8:
      break;
  
//Maxwell-Boltzmann distribution
    case 9:
      break;

//Most Probable Speed
    case 10:
      break;

//van der Waals Equation
    case 11:
      break;
  }
return 0;
}