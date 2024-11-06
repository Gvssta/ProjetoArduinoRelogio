import serial
import sqlite3

# Configurações da conexão serial
ser = serial.Serial('COM5', 9600)  # Substitua 'COM5' pela sua porta serial
print("Conectado à porta serial.")

# Configurações do banco de dados SQLite
conn = sqlite3.connect('dados_rfid.db')
c = conn.cursor()

# Cria a tabela se não existir
c.execute('''
    CREATE TABLE IF NOT EXISTS registros (
        id INTEGER PRIMARY KEY AUTOINCREMENT,
        uid TEXT NOT NULL,
        data TEXT NOT NULL,
        hora TEXT NOT NULL
    )
''')
conn.commit()

while True:
    line = ser.readline().decode('utf-8').strip()
    print(f"Linha lida: {line}")

    # Debug: Verifique se a linha lida começa com "VALID"
    if line.startswith("VALID"):
        try:
            _, uid, date, time = line.split(',')

            # Debug: Verifique os valores extraídos
            print(f"UID: {uid}, Data: {date}, Hora: {time}")

            # Armazena os dados no banco de dados
            c.execute('INSERT INTO registros (uid, data, hora) VALUES (?, ?, ?)', (uid.strip(), date.strip(), time.strip()))
            conn.commit()
            print("Dados armazenados no banco de dados.")

            # Imprime os dados armazenados
            c.execute('SELECT * FROM registros')
            registros = c.fetchall()

            for registro in registros:
                print(f"ID: {registro[0]}, UID: {registro[1]}, Data: {registro[2]}, Hora: {registro[3]}")

        except ValueError as e:
            print(f"Erro ao processar a linha: {line}. Erro: {e}")
    else:
        print("Dados inválidos, UID não reconhecido.")