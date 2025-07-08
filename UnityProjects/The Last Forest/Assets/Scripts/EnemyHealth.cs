using UnityEngine;

public class EnemyHealth : MonoBehaviour
{
    [Header("Health Settings")]
    public int maxHitPoints = 50; // Maximum hit points of the enemy
    public int currentHitPoints; // Current hit points of the enemy

    void Start()
    {
        currentHitPoints = maxHitPoints; // Set current hit points to maximum on start
    }

    // Method to handle damage to the enemy
    public void TakeDamage(int damageAmount)
    {
        currentHitPoints -= damageAmount; // Decrease hit points by the damage amount

        if (currentHitPoints <= 0)
        {
            Die(); // If hit points reach zero or less, call Die method
        }
    }

    // Method to handle enemy death
    void Die()
    {
        // Destroy the enemy GameObject when it dies
        Destroy(gameObject);
    }
}