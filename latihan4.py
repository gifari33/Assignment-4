import pandas as pd
import os

# Path input dan output
input_path = r'J:\Drive Saya\analisa sentimen git\percobaan 12\tokens_modified.csv'
output_path = r'J:\Drive Saya\analisa sentimen git\gojek_tokenize\tokens_modified.csv'

# Memastikan direktori tujuan ada
os.makedirs(os.path.dirname(output_path), exist_ok=True)

# Membaca data dari file CSV
data = pd.read_csv(input_path, low_memory=False)

# Menghapus kolom 'at' dan 'appVersion'
data_modified = data.drop(columns=['at', 'appVersion'])

# Menyimpan hasil ke file CSV baru
data_modified.to_csv(output_path, index=False)

print(f"Data telah disimpan ke {output_path}")
