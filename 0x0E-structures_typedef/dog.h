#ifndef DOG_H
#define DOG_H

/**
 * struct dog - Structure representing a dog
 * @name: Pointer to a string containing the dog's name
 * @age: Age of the dog
 * @owner: Pointer to a string containing the dog owner's name
 *
 * Description: This structure represents a dog and its attributes.
 */
struct dog
{
    char *name;
    float age;
    char *owner;
};

#endif /* DOG_H */

