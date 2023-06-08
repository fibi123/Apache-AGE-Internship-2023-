package main

import (
	"database/sql"
	"encoding/json"
	"fmt"
	"log"

	_ "github.com/lib/pq"
)

type User struct {
	UserID int            `json:"user_id"`
	Name   string         `json:"name"`
	Age    int            `json:"age"`
	Phone  sql.NullString `json:"phone,omitempty"`
}

func main() {
	// Establish a connection to the PostgreSQL database
	connStr := "postgres://postgres:1234@127.0.0.1:5432/dbname?sslmode=disable"
	db, err := sql.Open("postgres", connStr)
	if err != nil {
		log.Fatal(err)
	}
	defer db.Close()

	// Query the user_table
	rows, err := db.Query("SELECT * FROM user_table")
	if err != nil {
		log.Fatal(err)
	}
	defer rows.Close()

	var users []User

	// Iterate over the rows and create User objects
	for rows.Next() {
		var user User
		var phone sql.NullString
		err := rows.Scan(&user.UserID, &user.Name, &user.Age, &phone)
		if err != nil {
			log.Fatal(err)
		}
		if phone.Valid {
			user.Phone = phone
		}
		users = append(users, user)
	}

	// Marshal the users slice to JSON string
	jsonData, err := json.Marshal(users)
	if err != nil {
		log.Fatal(err)
	}

	// Print the JSON string
	fmt.Println(string(jsonData))
}
