terraform {
  required_providers {
    azurerm = {
      source = "hashicorp/azurerm"
      version = "3.90.0"
    }
  }
}

provider "azurerm" {
  # Configuration options
  features {}
}


# Create resource group
resource "azurerm_resource_group" "tr-rg-ne" {
  name = "tr-rg-ne-01"
  location = "North Europe"
}
