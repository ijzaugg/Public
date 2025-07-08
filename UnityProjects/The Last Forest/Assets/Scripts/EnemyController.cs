using UnityEngine;

public class EnemyController : MonoBehaviour
{
    public Vector3 treePosition; // Position where the tree is located

    public float movementSpeed = 3f; // Movement speed of the enemy

    private bool isMoving = true; // Flag to control enemy movement

    void Update()
    {
        if (isMoving)
        {
            // Calculate direction towards the tree position
            Vector3 direction = (treePosition - transform.position).normalized;

            // Move the enemy towards the tree position
            transform.Translate(direction * movementSpeed * Time.deltaTime);

            // Rotate the enemy to face the direction of movement (optional)
            transform.rotation = Quaternion.LookRotation(direction);
        }
    }

    // Method to stop the enemy movement
    public void StopMoving()
    {
        isMoving = false;
    }
}
