#! /bin/bash
# You can run this file and update all permissions by typing "bash permissions.sh" into your terminal. 
echo "Updating Permissions..."

# View Permissions
chmod -R 744 extras
chmod -R 744 teampics
chmod 744 style.css
chmod 711 extras
chmod 711 teampics

# Table Generation Permissions
chmod 744 tables.js

echo "Permission Updating Complete! See below:"

ls -l