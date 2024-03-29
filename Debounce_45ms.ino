// ======================== VARIÁVEIS =========================================================================================//
#define LED1 2
#define BT1 10
#define DebounceTime 45

bool LED1STATUS = 0;
bool BT1STATUS = 0;
// ============================================================================================================================= //

// ============================= FUNÇÃO DE ELIMINAÇÃO DEBOUNCE ==================================================================//

void Lebotoes();

// =============================================================================================================================//

// ============================== DEFINIÇÃO DE ENTRADAS E SAÍDAS ===============================================================//
void setup(){

pinMode(LED1,OUTPUT);
pinMode(BT1,INPUT);

}
// ==============================================================================================================================//

// ============================== FUNÇÃO PRINCIPAL ==============================================================================//
void loop(){

Lebotoes();
digitalWrite(LED1,BT1STATUS);

}

// ================================================================================================================================//

// ================================ DEBOUNCE ======================================================================================//

void Lebotoes(){

static bool BT1_FLAG = 0;
static long long BT1_DEBOUNCE = 0;            // variável statica //

if(!digitalRead(BT1) && !BT1_FLAG){         // leitura de status lógico do botão e sinalização de flag //
BT1_FLAG = 1;
BT1_DEBOUNCE = millis();
}

if (!digitalRead(BT1) && BT1_FLAG && (BT1_DEBOUNCE + DebounceTime < millis())) {

  BT1_DEBOUNCE = millis();
  BT1STATUS = 1;

}

if (digitalRead(BT1) && BT1_FLAG && (BT1_DEBOUNCE + DebounceTime < millis())) {

  BT1_FLAG = 0;
  BT1STATUS = 0;
}
}

//=============================== END ============================================================================================//