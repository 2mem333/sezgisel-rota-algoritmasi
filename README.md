# Heuristic Route Algorithm

*Optimization algorithm.*

## Abstract

In this project, I implemented the heuristic route algorithm, which was developed to solve problems related to minimum coverings, as a GUI application. I learned this algorithm in 2024 during my university studies from our professor Vasıf Nabiyev in the Discrete Mathematics course. Since this algorithm is very useful and I wanted to make it available online, I decided to create a public source for it.

## Understanding the problem

Lets begin with a story. Assume there are 10 locked safe vaults which are full of golds. And each vault's password is different. However, you're so lucky because there are 8 people who know passwords of some vaults.

<img width="1597" height="807" alt="image1" src="https://github.com/user-attachments/assets/cf924573-10ab-45d2-bca2-c859cbdea6f0" />

The safe vaults that these people know the passwords for are indicated on them in the picture. You can ask these people for passwords of vaults which they know. But there is one rule, you can only ask 3 person to get password of vaults they know. Now, you must choose three people in such a way that, with the passwords you learn from them, you can open the maximum number of safes. That way you will obtain more gold. Take your time and choose the people.

Well, how long did it take you to decide? If you succeed to open all safes then congratz you got all the golds. But if there are still some locked safes then you should try to pick 3 people again. Because by the end of the story, with an efficient choice you must be able to open all the safes. Let me give you order of these people, If you choose the 5th, 7th, and 8th person, you will see that a password can be obtained for every safe.

Since we are choosing 3 out of 8 people according to the rules of combinations, we have 56 different possible choices. Examining each of them one by one by brute force and then deciding on the choice that opens the most safes would require a lot of time and effort. At this point the human brain tries different strategies. For example, one might first pick the person who knows the most safe passwords, and then select two others who know the remaining passwords. Or, one might start by choosing a random person and then aim for each subsequent choice to maximize the number of different passwords obtained. However, people usually try to figure this out by experimenting and relying on chance.

Now is there an algorithm which we can use when we face a problem like this? So we can cover the entire universal set by selecting the minimum number of subsets. This problem may sound very much like a fairy tale but actually but in many moments of our lives, we actually face problems like this. For example, Wi-Fi internet needs to be provided to a residential area. The Wi-Fi access points must be placed so that the signal reaches every part of the area. Here, the goal is to cover the entire area using the minimum number of Wi-Fi points. In military, a country has air defense weapons with a certain range. These weapons must be positioned in such a way that the entire airspace can be protected using a minimum number of weapons.

## Heuristic Route Algorithm

For the question asked for an algorithm, the answer is yes. With the heuristics we can choose minimum subsets to cover universal set. To explain this algorithm lets back to our story.

<img width="1009" height="219" alt="image2" src="https://github.com/user-attachments/assets/6f17d8e4-ddd0-47ef-9d6c-86431e31b4d0" />


In the picture i gave letters to people to indicate them easily. To apply algorithm, we represent whole story with a 8x10 matris. In the rows will be people and columns will be safes. To fill matris cells, we only use 0 and 1. If the person who on the row of cell knows the password of safes which cell's corresponding column, the cell will be 1 otherwise it will be 0.

<p align="center">
<img width="500" height="450" alt="image3" src="https://github.com/user-attachments/assets/f8ad85e6-9b37-446d-9e03-0c59ec5f4eca" />
</p>

As you can see from the matris, if we select row a; 1st, 5th, 7th columns will be true. So, the goal is selecting the minimum number of rows while getting the maximum number of columns true Let's add a bit of heuristic into the process.

First, the weight of each column is calculated. The weight of a column is defined as the total number of true cells along that column. Next, the columns with the minimum weight are identified, and the rows corresponding to the true cells in these columns are marked.

For each of these marked rows, a weight is then calculated as follows:
[ ∑1/(weight of the active column) ]

Based on these calculations, the row with the lowest weight among the marked ones is removed from the matrix.

Note 1: While selecting a row, the concept of an absolute row arises. If there is a column with weight 1, the row corresponding to the true cell in that column is called the absolute row. In a matrix, if an absolute row exists, we select this row and remove it and its true columns from matrix.

Note 2: If there is a row where all columns are 1, this row is called a full row and has priority; it must be selected because it finishes the algorithm.

# Features of application

## Random matrix generation:
Creates a matrix with desired row and column dimensions and fills it with appropriate 0s and 1s **in a way suitable for applying the heuristic route algorithm**. It does not contain columns with weight 0 or 1, or absolute rows.

## Zero matrix generation:
Creates a matrix with desired row and column dimensions where all elements are 0, which can be updated with the "load matrix" button according to user preference.

## 9x10 default matrix:
Loads a suitable example matrix for the heuristic route that is saved in the system.

## Compatibility
The application is Windows-based and only works on this operating system. Users with other operating systems can use the console application at https://github.com/2mem333/sezgisel-rota-algoritmasi/blob/main/KonsolVersiyonu.cpp

# A few example screenshots from the application:

![Screenshot 2024-10-23 202449](https://github.com/user-attachments/assets/1bcdced2-9e03-4e9b-b1ea-492f7b4c5b51)
![Screenshot 2024-10-23 202416](https://github.com/user-attachments/assets/08fca332-cbde-4acc-9c9d-d0f379bd2dac)
![Screenshot 2024-10-23 202405](https://github.com/user-attachments/assets/8987d341-9947-4a90-817d-b2b3521070f3)
![Screenshot 2024-10-23 202435](https://github.com/user-attachments/assets/d7545b7d-7ed6-461c-95b9-8c09284c36ee)
