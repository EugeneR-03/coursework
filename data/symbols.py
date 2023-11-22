import os

def collect_symbols(directory):
    symbols = set()

    for root, dirs, files in os.walk(directory):
        for file in files:
            if file.endswith(".txt"):
                filepath = os.path.join(root, file)
                with open(filepath, "r") as f:
                    for line in f:
                        line = line.strip()
                        if line:
                            for char in line:
                                symbols.add(char)
    
    return symbols

directory = r"C:\Users\Evgeniy\Documents\Obsidian Vault\Q-система\Примеры описания Q-детерминантов"
symbols = collect_symbols(directory)
print(symbols)

# r"C:\Users\Evgeniy\Documents\Obsidian Vault\Q-система\Примеры описания Q-детерминантов"