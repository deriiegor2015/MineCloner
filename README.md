# 🎮 MineCloner - UE5 Minecraft Clone

**Повнофункціональна гра як Minecraft на Unreal Engine 5!**

## 🌟 Основні фічі

✅ **Блокова система** - видобуток, розміщення, фізика  
✅ **Інвентар** - 27 слотів, хоткей 1-9  
✅ **Світогенерація** - Perlin Noise, різні біоми  
✅ **Персонаж** - першовна особа, спринт  
✅ **Система крафту** - таблиця крафту, печь  
✅ **Мобів** - різні типи ворогів  
✅ **Виміри** - Overworld, Nether, End  
✅ **День/ніч цикл** - освітлення змінюється  
✅ **Збереження** - Save/Load функціонал  

---

## 📋 Архітектура

```
MineCloner/
├── Source/Public/
│   ├── BlockSystem.h
│   ├── ItemSystem.h
│   ├── InventoryComponent.h
│   ├── PlayerCharacter.h
│   ├── WorldGenerator.h
│   ├── SaveSystem.h
│   ├── MineCloneGameMode.h
│   └── MineCloneHUD.h
└── Source/Private/
    └── (реалізація .cpp файлів)
```

---

## 🚀 Швидкий старт

### 1. Клонувати репо
```bash
git clone https://github.com/deriiegor2015/MineCloner.git
cd MineCloner
```

### 2. Створити UE5 проект
- Запусти Unreal Engine 5
- New Project → Blank → C++ → Windows
- Назва: **MineCloner**

### 3. Копіювати файли
```
Copy Source/ файли в: YourProject/Source/MineCloner/
```

### 4. Компіляція
```bash
# Visual Studio
Build → Rebuild Solution

# Або в редакторі
Tools → Compile
```

### 5. Запуск
- Open in Editor → Play

---

## 🎮 Контроли

| Клавіша | Дія |
|---------|-----|
| **WASD** | Рух |
| **Mouse** | Погляд |
| **Space** | Стрибок |
| **Shift** | Спринт |
| **ЛКМ** | Видобути блок |
| **ПКМ** | Розмістити блок |
| **1-9** | Вибрати хоткей |

---

## 📚 Документація

Детальна документація в [README_MINECLONER.md](README_MINECLONER.md)

---

## 🔧 Системи

### BlockSystem
- Чанк-базована система (16x16x256)
- Dynamic LOD завантаження
- Видобуток/розміщення блоків

### InventorySystem
- 27 слотів інвентаря
- Хоткей (1-9)
- Здоров'я та голод система

### WorldGenerator
- Perlin Noise генерація
- Дерева, руди, печери
- Різні типи біомів

### SaveSystem
- JSON-базоване збереження
- Компресія чанків
- Auto-save функціонал

---

## 📊 Проект статус

- ✅ Sprint 1: Foundation
- ✅ Sprint 2: World Generation
- ✅ Sprint 3: Inventory
- 🚧 Sprint 4: Crafting (в розробці)
- ⏳ Sprint 5+: Наступні фічі

---

## 🤝 Як допомогти

1. Fork проект
2. Create feature branch
3. Commit changes
4. Push to branch
5. Create Pull Request

---

## 📝 Ліцензія

MIT License - вільна для використання

---

**Посилання:** [GitHub](https://github.com/deriiegor2015/MineCloner)

**Автор:** deriiegor2015

**Версія:** 0.1.0 (Early Development)

---

**Готові розробляти? Запустіть проект і почніть грати! 🎮🚀**