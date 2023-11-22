import os
import re

# Укажите путь к вашей папке
folder_path = r"C:\Users\Evgeniy\Documents\Obsidian Vault\Q-система\Примеры описания Q-детерминантов"

# Создание списка для хранения значений атрибута "op"
op_values = []

# Цикл для перебора всех файлов в папке
for subdir, dirs, files in os.walk(folder_path):
    for file in files:
        file_path = os.path.join(subdir, file)
        # Проверка расширения файла
        if file_path.endswith('.txt'):
            # Открытие файла
            with open(file_path, 'r') as f:
                lines = f.read()
                # Использование регулярных выражений для поиска атрибута "op"
                matches = re.findall(r'"op":"([^"]+)"', lines)
                # Добавление найденных значений в список op_values
                for match in matches:
                    if match not in op_values:
                        op_values.append(match)

# Вывод найденных значений атрибута "op"
print("Найденные значения атрибута 'op':")
for op_value in op_values:
    print(op_value)


# r"C:\Users\Evgeniy\Documents\Obsidian Vault\Q-система\Примеры описания Q-детерминантов"