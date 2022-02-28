#include "NumberTreatment.h"

void NumberToFile(double number, char *DataVector)
{
    unsigned int Buffer = (int)number;
    unsigned int temp = 0;
    //Calculo de parte Entera del numero decimal
    //Numero de Ejemplo
    DataVector[0] = (int)(Buffer/1000); 
    temp += DataVector[0] * 1000;
    DataVector[0] += 48;
    Buffer =(int)(number - temp);
    DataVector[1] = (int)(Buffer/100); 
    temp += DataVector[1] * 100;
    DataVector[1] += 48;
    Buffer =(int)(number - temp);
    DataVector[2] = (int)(Buffer/10); 
    temp += DataVector[2] * 10;
    DataVector[2] += 48;
    Buffer =(int)(number - temp);
    DataVector[3] = Buffer + 48;
    DataVector[4] = 0x2E;
    temp = 0;
    Buffer = (number - (int)number) * 1000;
    DataVector[5] = (int)(Buffer/100); 
    temp += DataVector[5] * 100;
    DataVector[5] += 48;
    Buffer =(int)(number - temp);
    DataVector[6] = (int)(Buffer/10); 
    temp += DataVector[6] * 10;
    DataVector[6] += 48;
    DataVector[7] =(int)(number - temp);
    DataVector[7] += 48;
}

void PrintNumber(float number, char *DataVector)
{
    unsigned int BufferNumber = (int)number;
    unsigned int Buffer = 0;
    DataVector[0] = (int)((BufferNumber - Buffer)/1000);
    Buffer =(DataVector[0] * 1000);
    DataVector[0] += 48;
    DataVector[1] = (int)((BufferNumber - Buffer)/100);
    Buffer += (DataVector[1] * 100);
    DataVector[1] += 48;
    DataVector[2] = (int)((BufferNumber - Buffer)/10);
    Buffer += (DataVector[2] * 10);
    DataVector[2] += 48;
    DataVector[3] = (int)((BufferNumber - Buffer));
    DataVector[3] += 48;
    DataVector[4] = 0x2E;
    //Calculo de Parte Fraccional
    BufferNumber = (number - (int)number) * 1000;
    Buffer = 0;
    DataVector[5] = (int)((BufferNumber - Buffer)/100);
    Buffer += DataVector[5] * 100;
    DataVector[5] += 48;
    DataVector[6] = (int)((BufferNumber - Buffer)/10);
    Buffer += DataVector[6] * 10;
    DataVector[6] += 48;
    DataVector[7] = (int)((BufferNumber - Buffer));
    DataVector[7] += 48;
}


void ShowNumber(float number, float resolution, char *DataVector)
{
    //Data Vector = {UnidadesMillas,Centenas, Decenas, Unidades, dp, Decimas,Centesimas,Milesimas}
    unsigned int PteEntera = 0;
    unsigned int PteFraccion = 0;
    char UnidadesMillar = 0;
    char Centenas = 0;
    char Decenas = 0;
    char Unidades = 0;
    char Decimas = 0;
    char Centesimas = 0;
    char Milesimas = 0;
    float buffer = 0;
    PteEntera = (int)number;
    PteFraccion = (number - PteEntera) / resolution;
    UnidadesMillar = (int)(PteEntera/1000);
    Centenas = (int)((PteEntera - (UnidadesMillar * 1000))/100);
    Decenas =(int)( (PteEntera - (UnidadesMillar * 1000) - (Centenas *100)) / 10);
    Unidades = (int)(PteEntera - (UnidadesMillar *1000) - (Centenas *100) - (Decenas * 10)); 
    Decimas = (int)(PteFraccion/100);
    Centesimas = (int)(PteFraccion - (Decimas * 100))/10;
    Milesimas = (int)(PteFraccion - (Decimas*100) - (Centesimas * 10));
    DataVector[0] = UnidadesMillar + 48;
    DataVector[1] = Centenas + 48;
    DataVector[2] = Decenas + 48;
    DataVector[3] = Unidades + 48;
    DataVector[4] = 0x2E;
    DataVector[5] = Decimas + 48;
    DataVector[6] = Centesimas + 48;
    DataVector[7] = Milesimas + 48;
}

unsigned int ParteEntera(float number )
{
    return (int)number;
}

unsigned int ParteFraccional(float number, float resolution)
{
    float buffer = 0;
    buffer =(number - (int) number) / resolution; 
    return buffer;
}