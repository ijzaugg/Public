using UnityEngine;

public class Grabber : MonoBehaviour
{
    public Transform grabPoint; // The point from which objects are grabbed
    public LayerMask grabbableLayer; // The layer(s) on which grabbable objects are located
    public int magicChargesToAdd = 5; // Number of magic charges to add when releasing the fruit
    public float attackRange = 10f; // Range of the attack

    private Grabbable currentGrabbable; // Reference to the currently grabbed object

    void Update()
    {
        // Check for grabbing input
        if (Input.GetButtonDown("Grab")) // Change to the input for grabbing (e.g., Oculus controller input)
        {
            TryGrab();
        }

        // Check for attacking input
        if (Input.GetButtonDown("Attack")) // Change to the input for attacking (e.g., trigger pull)
        {
            TryAttack();
        }
    }

    void TryGrab()
    {
        if (currentGrabbable == null) // If not currently holding an object
        {
            RaycastHit hit;
            if (Physics.Raycast(grabPoint.position, grabPoint.forward, out hit, Mathf.Infinity, grabbableLayer))
            {
                currentGrabbable = hit.collider.GetComponent<Grabbable>();
                if (currentGrabbable != null)
                {
                    currentGrabbable.transform.SetParent(grabPoint); // Attach grabbed object to grab point
                    currentGrabbable.transform.localPosition = Vector3.zero; // Center the grabbed object
                    currentGrabbable.Grab();
                    // Add any additional logic you need when an object is grabbed
                }
            }
        }
        else // If already holding an object, release it
        {
            ReleaseGrabbable();
        }
    }

    void TryAttack()
    {
        RaycastHit hit;
        if (Physics.Raycast(grabPoint.position, grabPoint.forward, out hit, attackRange))
        {
            // Check if the hit object is an enemy
            EnemyHealth enemyHealth = hit.collider.GetComponent<EnemyHealth>();
            if (enemyHealth != null)
            {
                // Perform attack on the enemy (e.g., decrease its health)
                enemyHealth.TakeDamage(10); // Example: decrease enemy health by 10
            }
        }
    }

    void ReleaseGrabbable()
    {
        if (currentGrabbable.CompareTag("Fruit")) // Check if the grabbed object is a fruit
        {
            currentGrabbable.Release();
            currentGrabbable.transform.SetParent(null); // Release the grabbed object from grab point
            // Add logic to make the fruit disappear (e.g., deactivate or destroy it)
            Destroy(currentGrabbable.gameObject);
            // Add charges of magic to the player's magic ability
            AddMagicCharges();
        }
        currentGrabbable = null;
        // Add any additional logic you need when an object is released
    }

    void AddMagicCharges()
    {
        Debug.Log("Added " + magicChargesToAdd + " charges of magic to the player's magic ability.");
    }
}
