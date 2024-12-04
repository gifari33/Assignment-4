import pandas as pd

# Tentukan path file CSV
file_path = "J:\\Drive Saya\\analisa sentimen git\\percobaan 12\\tokens_modified.csv"

# Baca file CSV menggunakan Pandas
df = pd.read_csv(file_path)

# Tampilkan 5 baris pertama dari DataFrame
print(df.head())