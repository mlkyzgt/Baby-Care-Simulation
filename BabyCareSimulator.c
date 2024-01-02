#include <stdio.h>
#include <stdlib.h>
char *needs[] = {"Satiety", "Sleep", "Love", "Socialization", "Health", "Education", "Thirst", "Hygiene", "Toilet", "Entertainment", "Peace", "Learning", "Security"};
int need_levels[] = {10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 20};
int initial_needs[] = {10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 20};
void showNeedLevels(int *need_levels);
int isBabyDead(int *need_levels);
void resetNeeds(int *need_levels);
int decrease(int *needs_levels);
void eat(int *need_levels);
void sleep(int *need_levels);
void showLove(int *need_levels);
void socialize(int *need_levels);
void healthCare(int *need_levels);
void education(int *need_levels);
void quenchThirst(int *need_levels);
void maintainHygiene(int *need_levels);
void useToilet(int *need_levels);
void haveFun(int *need_levels);
void ensureSafety(int *need_levels);

int main()
{
    int choice;
    printf("Hello, welcome to your virtual baby Rarity! You can develop Rarity by choosing one of the options below. However, your money and peace will be affected by your choices, and the levels of these options will increase or decrease accordingly in the future. If health, satiety, thirst, or money levels drop to or below 0, the baby will die, and the game will reset.\nPress -1 to exit the game.\n");

    do
    {
        printf("1: Satiety\n2: Sleep\n3: Love\n4: Socialization\n5: Health\n6: Education\n7: Thirst\n8: Hygiene\n9: Toilet\n10: Entertainment\n11: Peace\n12: Learning\n13: Security\nYour choice: ");
        scanf("%d", &choice);
        printf("\n");

        if (isBabyDead(need_levels) == 1)
        {
            return 1;
        }

        switch (choice)
        {
        case 1:
            printf("Great! You wanted to feed Rarity. Now, enter the number of the food you want to feed Rarity!\n");
            eat(need_levels);
            decrease(need_levels);
            showNeedLevels(need_levels);
            break;

        case 2:
            printf("Great! Rarity was very sleepy. Now, choose a number between 1 and 4 to indicate how Rarity will sleep.\n");
            sleep(need_levels);
            showNeedLevels(need_levels);
            break;

        case 3:
            printf("You wanted to show love to Rarity. Rarity is very excited because you will love her.\n");
            showLove(need_levels);
            break;

        case 4:
            printf("It was the perfect time to socialize with Rarity! What will you do?\n");
            socialize(need_levels);
            break;

        case 5:
            printf("What will you do for Rarity's health?\n");
            healthCare(need_levels);
            break;

        case 6:
            printf("What will you do for Rarity's education?\n");
            education(need_levels);
            showNeedLevels(need_levels);
            break;

        case 7:
            printf("What will you do to quench Rarity's thirst?\n");
            quenchThirst(need_levels);
            showNeedLevels(need_levels);
            break;

        case 8:
            printf("What will you do for Rarity's hygiene?\n");
            maintainHygiene(need_levels);
            showNeedLevels(need_levels);
            break;

        case 9:
            printf("What will you do for Rarity's toilet needs?\n");
            useToilet(need_levels);
            showNeedLevels(need_levels);
            break;

        case 10:
            printf("What will you do for Rarity's entertainment?\n");
            haveFun(need_levels);
            showNeedLevels(need_levels);
            break;

        case 11:
            printf("What will you do for Rarity's peace?\n");
            ensureSafety(need_levels);
            showNeedLevels(need_levels);
            break;

        default:
            printf("Invalid choice. Please make another selection.\n");
            break;
        }

        isBabyDead(need_levels);

    } while (choice != -1);

    return 0;
}
void resetNeeds(int *need_levels)
{
    for (int i = 0; i < 13; ++i)
    {
        need_levels[i] = initial_needs[i];
    }
}

int isBabyDead(int *needs_levels)
{
    if (needs_levels[0] <= 0)
    {
        printf("The baby died of hunger! The game is resetting.\n");
        resetNeeds(needs_levels);
        showNeeds(needs_levels);
    }
    else if (needs_levels[7] <= 0)
    {
        printf("The baby wet its diaper, and hygiene level is reset to zero.\n");
        needs_levels[7] = 0;
    }
    else if (needs_levels[4] <= 0)
    {
        printf("The baby died! The game is resetting.\n");
        resetNeeds(needs_levels);
        showNeeds(needs_levels);
    }
    else if (needs_levels[6] <= 0)
    {
        printf("The baby died of thirst! The game is resetting.\n");
        resetNeeds(needs_levels);
        showNeeds(needs_levels);
    }
    else if (needs_levels[12] <= 0)
    {
        printf("The baby died due to poverty! The game is resetting.\n");
        resetNeeds(needs_levels);
        showNeeds(needs_levels);
    }

    return 0;
}

int decrease(int *need_levels)
{
    for (int i = 0; i < 13; i++)
    {
        need_levels[i] -= 1;
        need_levels[4] += 1;
    }
    return 0;
}

void eat(int *need_levels)
{
    char food_choice_str[10];
    char quantity_str[10];

    printf("Food choice: ");
    scanf("%s", food_choice_str);

    printf("Quantity: ");
    scanf("%s", quantity_str);

    int food_choice = atoi(food_choice_str);
    int quantity = atoi(quantity_str);

    switch (food_choice)
    {
    case 1:
        printf("You ate %d servings of Apple Puree.\n", quantity);
        need_levels[0] += 3 * quantity;
        need_levels[4] += 1 * quantity;
        need_levels[12] -= 2 * quantity;
        break;
    case 2:
        printf("You ate %d servings of Chocolate.\n", quantity);
        need_levels[0] += 2 * quantity;
        need_levels[4] -= 2 * quantity;
        need_levels[12] -= 2 * quantity;
        break;
    case 3:
        printf("You ate %d servings of Broccoli.\n", quantity);
        need_levels[0] += 2 * quantity;
        need_levels[4] += 1 * quantity;
        need_levels[12] -= 2 * quantity;
        break;
    case 4:
        printf("You ate %d servings of Eggs.\n", quantity);
        need_levels[0] += 3 * quantity;
        need_levels[4] += 1 * quantity;
        need_levels[12] -= 1 * quantity;
        break;
    case 5:
        printf("You drank the Hunger Elixir. Your hunger level is now complete at 10.\n");
        need_levels[0] = 10;
        need_levels[12] -= 4;
        break;
    default:
        printf("Invalid option. Please try again.\n");
        break;
    }
}
void sleep(int *need_levels)
{
    int sleep_choice;
    scanf("%d", &sleep_choice);

    switch (sleep_choice)
    {
    case 1:
        printf("Congratulations, you chose deep sleep! Rarity slept soundly.\n");
        printf("Sleep: +2\nPeace: +2\n");
        need_levels[1] += 2;
        need_levels[10] += 2;
        need_levels[12] += 6;
        break;
    case 2:
        printf("You chose light sleep! But it was not enough for Rarity. Make another choice.\n");
        printf("Sleep: +0.5\n");
        need_levels[1] += 1;
        sleep(need_levels);
        break;
    case 3:
        printf("Oh no! Rarity had a nightmare. Her peace was disturbed, and she couldn't sleep. Do you want to give her love?\n1: Yes 2: No\n");
        int choice1;
        scanf("%d", &choice1);

        switch (choice1)
        {
        case 1:
            showLove(need_levels);
            printf("Rarity is now more peaceful because you gave her love, but she still needs sleep!\n");
            break;
        case 2:
            printf("Rarity is very sad because you didn't show her love, and she still needs sleep.\n");
            need_levels[2] -= 1;
            break;
        default:
            printf("You made a wrong choice. Please make another choice.\n");
            break;
        }

        printf("Peace: -2\n");
        need_levels[10] -= 3;
        sleep(need_levels);
        break;
    case 4:
        printf("Rarity couldn't sleep. Make another choice.\n");
        printf("Peace: -1\n");
        need_levels[10] -= 1;
        sleep(need_levels);
        break;
    default:
        break;
    }
}
void showLove(int *need_levels)
{
    int love_choice;

    printf("1. Hug\n2. Kiss\n3. Carry\n4. Pet on the head\n");
    printf("Your choice: ");
    scanf("%d", &love_choice);
    printf("\n");

    switch (love_choice)
    {
    case 1:
        need_levels[2] += 1;
        need_levels[10] += 1;
        need_levels[12] -= 1;
        need_levels[4] -= 2;
        printf("Oh no! When you hugged Rarity, she said her bones hurt.\n");
        healthCare(need_levels);
        break;
    case 2:
        need_levels[2] += 2;
        need_levels[10] += 1;
        need_levels[12] -= 1;
        need_levels[4] -= 2;
        printf("Oh no! When you kissed Rarity, you noticed she had a fever.\n");
        healthCare(need_levels);
        break;
    case 3:
        printf("You carried Rarity in your arms! Rarity is very happy.\n");
        need_levels[2] += 1;
        need_levels[10] += 1;
        need_levels[12] += 4;
        break;
    case 4:
        printf("You petted Rarity's head. Rarity is now happier!\n");
        need_levels[2] += 1;
        need_levels[10] += 1;
        need_levels[12] += 4;
        break;
    default:
        printf("You made a wrong choice. Please make another choice.\n");
        break;
    }
}
void socialize(int *need_levels)
{
    int socialize_choice, choice2;

    printf("1. Join the Baby Group\n2. Visit Family\n3. Go to the Park\n");
    printf("Your choice: ");
    scanf("%d", &socialize_choice);
    printf("\n");

    switch (socialize_choice)
    {
    case 1:
        printf("You decided to join the baby group. Rarity loved her new friends!\n");
        need_levels[2] += 3;
        need_levels[3] += 2;
        need_levels[10] += 1;
        break;
    case 2:
        printf("You went to visit family. Your family entertained Rarity a lot.\n");
        need_levels[2] += 2;
        need_levels[3] += 3;
        need_levels[10] += 2;
        break;
    case 3:
        printf("You decided to go to the park. What equipment will you put Rarity on?\n");
        printf("1. Slide\n2. Swing\n3. Seesaw\nYour choice: ");
        scanf("%d", &choice2);
        printf("\n");

        switch (choice2)
        {
        case 1:
            printf("Rarity loved the slide!");
            need_levels[2] += 3;
            need_levels[3] += 4;
            need_levels[9] += 3;
            need_levels[10] += 2;
            break;
        case 2:
            printf("Rarity loves the swing the most! She had a lot of fun.");
            need_levels[2] += 3;
            need_levels[3] += 4;
            need_levels[9] += 4;
            need_levels[10] += 3;
            break;
        case 3:
            printf("Rarity didn't enjoy the seesaw at all.");
            need_levels[2] += 1;
            need_levels[3] += 2;
            need_levels[9] += 1;
            need_levels[10] -= 1;
            break;
        default:
            break;
        }
        break;
    default:
        break;
    }
}
void healthCare(int *need_levels)
{
    int health_choice, choice2, choice3;

    printf("1. Go to the Doctor.\n2. Take care at home.\n3. Drink a Health Potion.\nYour choice: ");
    scanf("%d", &health_choice);
    printf("\n");

    switch (health_choice)
    {
    case 1:
        printf("You immediately took Rarity to the doctor.\nDoctor: To solve the problem, we can use an injection or medicine. But the injection will solve the problem more quickly. I leave the choice to you.\n1. Injection\n2. Medicine\n3. I don't want her to use anything.\nYour choice: ");
        scanf("%d", &choice2);

        switch (choice2)
        {
        case 1:
            printf("You chose to get an injection. Rarity's problem was solved, but it hurt a lot. She's crying.");
            need_levels[4] += 1;
            need_levels[10] -= 2;
            break;
        case 2:
            printf("You chose to take medicine. Rarity liked the taste of the medicine, but what's this? Oh no, Rarity is allergic to the medicine!");
            need_levels[4] -= 2;
            need_levels[10] -= 1;
            printf("For Rarity's health, what will you do?\n1. Go to the Doctor.\n2. Take care at home.\n3. Drink a Health Potion.\nYour choice: ");

            scanf("%d", &choice3);
            switch (choice3)
            {
            case 1:
                printf("Thank goodness! Rarity is saved because you chose to go to the doctor, but her health didn't improve much.");
                need_levels[10] += 1;
                break;
            case 2:
                need_levels[4] = 0;
                break;
            case 3:
                printf("Fantastic! You chose the Health Potion. Rarity is completely healed.");
                need_levels[12] -= 5;
                need_levels[4] = 10;
                break;
            default:
                printf("You made a wrong choice. Please make another choice.");
                break;
            }
            break;
        default:
            printf("You made a wrong choice. Please make another choice.");
            break;
        }

        need_levels[12] -= 2;
        break;
    case 2:
        printf("You chose to take care at home. Unfortunately, Rarity's condition worsened over time.\n");
        need_levels[4] -= 1;
        need_levels[10] -= 1;
        healthCare(need_levels);
        break;

    case 3:
        printf("Great! You chose the Health Potion. Rarity is completely healed.");
        need_levels[4] = 10;
        need_levels[12] -= 5;
        need_levels[10] += 2;
        break;
    default:
        printf("You made a wrong choice. Please make another choice.");
        break;
    }
}
void education(int *need_levels)
{
    int education_choice, choice2, choice3;
    printf("1. Motor Skills Training\n2. Sensory Development\n3. Social Skills\n");
    printf("Your choice: ");
    scanf("%d", &education_choice);
    printf("\n");

    switch (education_choice)
    {
    case 1:
        printf("You chose Motor Skills Training. What kind of training would you like to give?\n");
        printf("1. Walking Training\n2. Swimming Training\n3. Cutting and Pasting Training\nYour choice: ");
        scanf("%d", &choice2);
        printf("\n");

        switch (choice2)
        {
        case 1:
            printf("You chose Walking Training. Rarity made good progress, even though she occasionally falls.\n");
            need_levels[0] -= 2;
            need_levels[1] -= 2;
            need_levels[5] += 2;
            break;
        case 2:
            printf("You chose Swimming Training! Rarity loves water and swimming!\n");
            need_levels[0] -= 2;
            need_levels[1] -= 2;
            need_levels[5] += 2;
            need_levels[6] -= 2;
            need_levels[9] += 3;
            need_levels[12] -= 2;
            break;
        case 3:
            printf("You chose Cutting and Pasting Training. Rarity loves doing handicrafts. She had a lot of fun during the training.\n");
            need_levels[1] -= 2;
            need_levels[9] += 4;
            need_levels[10] += 2;
            break;
        default:
            printf("You selected a non-existent option.\n");
            break;
        }
        break;
    case 2:
        printf("You chose Sensory Development Training. What kind of training would you like to give?\n");
        printf("1. Tactile\n2. Auditory\n3. Visual\nYour choice: ");
        scanf("%d", &choice2);
        printf("\n");

        switch (choice2)
        {
        case 1:
            printf("To support Rarity's tactile development, you played with objects of different shapes. Rarity enjoyed it very much.\n");
            need_levels[0] -= 1;
            need_levels[1] -= 1;
            need_levels[5] += 2;
            need_levels[10] += 1;
            break;
        case 2:
            printf("To support Rarity's auditory development, you bought her a toy that plays music. Rarity really loves her new toy.\n");
            need_levels[0] -= 2;
            need_levels[1] -= 2;
            need_levels[5] += 2;
            need_levels[6] -= 1;
            need_levels[9] += 3;
            need_levels[12] -= 3;
            break;
        case 3:
            printf("To support Rarity's visual development, you showed her shapes in different colors and told her their names. Rarity learned new information.\n");
            need_levels[0] -= 2;
            need_levels[1] -= 2;
            need_levels[5] += 2;
            need_levels[6] -= 1;
            break;
        default:
            printf("You selected a non-existent option.\n");
            break;
        }
        break;
    case 3:
        printf("You chose Social Skills Training. What kind of training would you like to give?\n");
        printf("1. Making Friends\n2. Playing Games\n3. Reading Books\nYour choice: ");
        scanf("%d", &choice2);
        printf("\n");

        switch (choice2)
        {
        case 1:
            printf("Great! You wanted to make new friends with Rarity. So who will be her new friend?\n");
            printf("1. Twilight\n2. Starlight\n3. Celestia\nYour choice: ");
            scanf("%d", &choice3);
            printf("\n");

            switch (choice3)
            {
            case 1:
                printf("Awesome! Twilight and Rarity got along very well.");
                need_levels[2] += 3;
                need_levels[3] += 2;
                need_levels[10] += 1;
                break;
            case 2:
                printf("Oh no! Starlight and Rarity didn't get along at all. Starlight pushed Rarity away.");
                need_levels[2] -= 2;
                need_levels[3] -= 1;
                need_levels[10] -= 3;
                break;
            case 3:
                printf("Celestia didn't get along well with Rarity because she is older, but she watched over Rarity like a big sister.");
                need_levels[2] += 1;
                need_levels[3] += 1;
                need_levels[10] += 2;
                break;
            default:
                printf("You selected a non-existent option.\n");
                break;
            }
            break;
        case 2:
            printf("Great! You played games with Rarity, and she had a lot of fun.\n");
            need_levels[9] += 5;
            need_levels[1] -= 2;
            need_levels[10] += 3;
            break;
        case 3:
            printf("You read a book to Rarity. She got very sleepy while reading.\n");
            need_levels[1] += 3;
            need_levels[9] += 2;
            need_levels[10] += 1;
            break;
        default:
            printf("You selected a non-existent option.\n");
            break;
        }
        break;
    default:
        printf("You selected a non-existent option.\n");
        break;
    }
}
void thirst(int *need_levels)
{
    int drink_choice;
    printf("1. Water\n2. Coffee\n3. Fruit Juice\n");
    printf("Your choice: ");
    scanf("%d", &drink_choice);
    printf("\n");

    switch (drink_choice)
    {
    case 1:
        printf("You chose water. You relieved Rarity's thirst!\n");
        need_levels[6] += 2;
        need_levels[4] += 1;
        need_levels[12] -= 1;
        need_levels[8] -= 2;
        break;
    case 2:
        printf("You chose coffee, but Rarity is still a baby! Her heart rate got disturbed, and Rarity passed away.\n");
        need_levels[4] = 0;
        break;
    case 3:
        printf("You chose fruit juice. Rarity both loved the fruit juice and quenched her thirst!\n");
        need_levels[4] += 1;
        need_levels[6] += 2;
        need_levels[8] -= 2;
        need_levels[10] += 1;
        need_levels[12] -= 2;
        break;
    default:
        printf("Invalid choice. Please enter a valid option.\n");
        break;
    }
}
void hygiene(int *need_levels)
{
    int hygiene_choice, choice2;
    printf("1. Clothing Cleanliness\n2. Tooth Brushing\n3. Bath\n");
    printf("Your choice: ");
    scanf("%d", &hygiene_choice);
    printf("\n");

    switch (hygiene_choice)
    {
    case 1:
        printf("You chose clothing cleanliness. Rarity got very fussy when taking off her clothes. Don't forget to show her some love.\n");
        need_levels[7] += 1;
        need_levels[10] -= 2;
        break;
    case 2:
        printf("You chose tooth brushing. Rarity loved brushing her teeth!\n");
        need_levels[7] += 1;
        break;
    case 3:
        printf("You chose to give Rarity a bath. How will you give her a bath?\n1. Bubble Bath\n2. Bath with Toys\n3. Classic Bath\nYour choice: ");
        scanf("%d", &choice2);

        if (choice2 == 1)
        {
            printf("Rarity loved the bubble bath!\n");
            need_levels[12] -= 1;
        }
        else if (choice2 == 2)
        {
            printf("Rarity loved the bath with toys!\n");
            need_levels[12] -= 2;
        }
        else if (choice2 == 3)
        {
            printf("There was nothing to distract Rarity's attention in the bath, so her peace got disturbed!\n");
            need_levels[10] -= 1;
        }
        else
        {
            printf("You made an incorrect choice.\n");
        }

        printf("\n");
        need_levels[7] += 1;
        need_levels[12] -= 2;
        break;
    default:
        break;
    }
}
void toilet(int *need_levels)
{
    int toilet_choice;
    printf("1. Diaper Change\n2. Toilet Training\n3. Post-Toilet Hygiene\n");
    printf("Your choice: ");
    scanf("%d", &toilet_choice);
    printf("\n");

    switch (toilet_choice)
    {
    case 1:
        printf("You changed Rarity's diaper!\n");
        need_levels[7] += 1;
        need_levels[8] += 3;
        break;
    case 2:
        printf("You gave toilet training to Rarity.\n");
        need_levels[8] += 3;
        need_levels[5] += 2;
        break;
    case 3:
        printf("You chose post-toilet hygiene.\n");
        need_levels[8] += 1;
        need_levels[7] += 3;
        break;
    default:
        printf("Invalid choice. Please try again.\n");
        break;
    }
}

void entertainment(int *need_levels)
{
    int entertainment_choice;
    printf("1. Music Activity\n2. Building with Lego\n3. Drawing\nYour choice: ");
    scanf("%d", &entertainment_choice);
    printf("\n");

    switch (entertainment_choice)
    {
    case 1:
        printf("You chose the music activity. Rarity had a great time!\n");
        need_levels[9] += 2;
        need_levels[10] += 3;
        break;
    case 2:
        printf("You chose to build with Lego. Rarity created beautiful things with Lego.\n");
        need_levels[9] += 1;
        need_levels[10] += 2;
        break;
    case 3:
        printf("You chose to draw. Rarity got lost in drawing.\n");
        need_levels[9] += 2;
        need_levels[10] += 2;
        break;
    default:
        printf("Invalid choice. Please try again.\n");
        break;
    }
}
void security(int *need_levels)
{
    int security_choice;
    printf("1. Lock the door.\n2. Check the stove.\n3. Install an alarm.\nYour choice: ");
    scanf("%d", &security_choice);
    printf("\n");

    switch (security_choice)
    {
    case 1:
        printf("Locking the door selected.\n");
        need_levels[11] += 2;
        break;
    case 2:
        printf("Stove check selected.\n");
        need_levels[11] += 2;
        break;
    case 3:
        printf("Installing an alarm selected.\n");
        need_levels[11] += 3;
        need_levels[12] -= 2;
        break;
    default:
        printf("Invalid choice. Please try again.\n");
        break;
    }
}
