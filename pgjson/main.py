import json
from decimal import Decimal
import psycopg2

class DecimalEncoder(json.JSONEncoder):
    def default(self, o):
        if isinstance(o, Decimal):
            return float(o)
        return super().default(o)

# Establish a connection to the PostgreSQL database
conn = psycopg2.connect(
    host="127.0.0.1",
    user="postgres",
    password="1234",
    dbname="dbname"
)
cursor = conn.cursor()

# Query the user_table
cursor.execute("SELECT * FROM user_table")
users = []

# Iterate over the rows and create User objects
for row in cursor.fetchall():
    user_id, name, age, phone = row
    user = {
        "user_id": int(user_id),
        "name": name,
        "age": int(age),
        "phone": phone if phone else None
    }
    users.append(user)

# Convert the users list to JSON string
json_data = json.dumps(users, cls=DecimalEncoder)

# Print the JSON string
print(json_data)
