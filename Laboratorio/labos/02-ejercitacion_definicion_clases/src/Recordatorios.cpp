#include <iostream>
#include <list>

using namespace std;

using uint = unsigned int;

// Pre: 0 <= mes < 12
uint dias_en_mes(uint mes) {
    uint dias[] = {
        // ene, feb, mar, abr, may, jun
        31, 28, 31, 30, 31, 30,
        // jul, ago, sep, oct, nov, dic
        31, 31, 30, 31, 30, 31
    };
    return dias[mes - 1];
}

// Ejercicio 7, 8, 9 y 10

// Clase Fecha
class Fecha {
  public:
    Fecha(int mes, int dia);
    int mes();
    int dia();
    #if EJ >= 9 // Para ejercicio 9
    bool operator==(Fecha o);
    bool operator<(Fecha f);
    #endif
    void incrementar_dia();

  private:
    int dia_;
    int mes_;
};

Fecha::Fecha(int mes, int dia): dia_(dia), mes_(mes) {}

int Fecha::dia() {
    return dia_;
}

int Fecha::mes() {
    return mes_;
}

ostream& operator<<(ostream& os, Fecha fecha) {
    os << fecha.dia() << "/" << fecha.mes();
    return os;
}

#if EJ >= 9
bool Fecha::operator==(Fecha o) {
    bool igual_dia = this->dia() == o.dia();
    bool igual_mes = this->mes() == o.mes();
    return igual_dia and igual_mes;
}
#endif

void Fecha::incrementar_dia() {
    this->dia_++;
    // cambio de mes
    if (this->dia_ > dias_en_mes(this->mes_)) {
        this->dia_ = 1;
        this->mes_++;
    }
    // cambio de anio
    if (this->mes_ > 12) {
        this->mes_ = 1;
    }
}

bool Fecha::operator<(Fecha fecha) {
    bool menor_fecha;
    if (this->mes() == fecha.mes()) {
        menor_fecha = this->dia() < fecha.dia();
    } else {
        menor_fecha = this->mes() < fecha.mes();
    }
    return menor_fecha;
}

// Ejercicio 11, 12

// Clase Horario

class Horario {
public:
    Horario(uint hora, uint min);
    uint hora() const;
    uint min() const;
    bool operator==(Horario horario);
    bool operator<(Horario horario);
private:
    uint hora_;
    uint min_;
};

Horario::Horario(uint hora, uint min): hora_(hora), min_(min) {}

uint Horario::hora() const {
    return hora_;
}

uint Horario::min() const {
    return min_;
}

bool Horario::operator==(Horario horario) {
    bool misma_hora = this->hora() == horario.hora();
    bool mismos_minutos = this->min() == horario.min();
    return misma_hora and mismos_minutos;
}

ostream& operator<<(ostream& os, Horario horario) {
    os << horario.hora() << ":" << horario.min();
    return os;
}

bool Horario::operator<(Horario horario) {
    bool menor_horario;
    if (this->hora() == horario.hora()) {
        menor_horario = this->min() < horario.min();
    } else {
        menor_horario = this->hora() < horario.hora();
    }
    return menor_horario;
}
// Ejercicio 13

// Clase Recordatorio

class Recordatorio {
public:
    Recordatorio(Fecha f, Horario h, string m);
    Fecha fecha();
    Horario horario();
    string mensaje();
    bool operator<(Recordatorio recordatorio);

private:
    Fecha fecha_;
    Horario horario_;
    string mensaje_;
};

Recordatorio::Recordatorio(Fecha f, Horario h, string m): fecha_(f), horario_(h), mensaje_(m) {}

Fecha Recordatorio::fecha() {
    return fecha_;
}

Horario Recordatorio::horario() {
    return horario_;
}

string Recordatorio::mensaje() {
    return mensaje_;
}

bool Recordatorio::operator<(Recordatorio recordatorio) {
    bool menor_recordatorio;
    if (this->fecha() == recordatorio.fecha()) {
        menor_recordatorio = this->horario() < recordatorio.horario();
    } else {
        menor_recordatorio = this->fecha() < recordatorio.fecha();
    }
    return menor_recordatorio;
}

ostream& operator<<(ostream& os, Recordatorio recordatorio) {
    os << recordatorio.mensaje() << " @ " << recordatorio.fecha() << " " << recordatorio.horario();
    return os;
}

// Ejercicio 14

// Clase Agenda

class Agenda {
public:
    Agenda(Fecha fecha_inicial);
    void agregar_recordatorio(const Recordatorio& recordatorio);
    void incrementar_dia();
    list<Recordatorio> recordatorios_de_hoy();
    Fecha hoy();

private:
    Fecha hoy_;
    list<Recordatorio> recordatorios_;
};

Agenda::Agenda(Fecha fecha_inicial): hoy_(fecha_inicial) {}

list<Recordatorio> Agenda::recordatorios_de_hoy() {
    list<Recordatorio> recordatorios_de_hoy;
    for (Recordatorio rec: this->recordatorios_) {
        if (this->hoy_ == rec.fecha()) {
            recordatorios_de_hoy.push_back(rec);
        }
    }
    recordatorios_de_hoy.sort();
    return recordatorios_de_hoy;
}

void Agenda::agregar_recordatorio(const Recordatorio& recordatorio) {
    this->recordatorios_.push_back(recordatorio);
}

void Agenda::incrementar_dia() {
    this->hoy_.incrementar_dia();
}

Fecha Agenda::hoy() {
    return this->hoy_;
}

ostream& operator<<(ostream& os, Agenda agenda) {
    os << agenda.hoy() << endl;
    os << "=====" << endl;

    for (const Recordatorio& rec: agenda.recordatorios_de_hoy()) {
        os << rec << endl;
    }
    return os;
}
