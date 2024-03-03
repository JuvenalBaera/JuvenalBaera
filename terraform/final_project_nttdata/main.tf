# az login
# terraform init
# terraform plan
# terraform apply

terraform {
  required_providers {
    azurerm = {
        source = "hashicorp/azurerm"
        version = ">=3.90"
    }
  }
}

provider "azurerm" {
  features {}
}

# resource group
resource "azurerm_resource_group" "tf_rg_ne" {
  name      = "tf-rg-ne-02"
  location = "North Europe"
}


# Virtual network
resource "azurerm_virtual_network" "tf_vnet_ne" {
  name                  = "tf-vnet-ne-01"
  resource_group_name   = azurerm_resource_group.tf_rg_ne.name
  location              = azurerm_resource_group.tf_rg_ne.location
  address_space         = ["10.0.0.0/16"]
}

# Sub net 1
resource "azurerm_subnet" "tf_snet_ne_01" {
  name                  = "tf-snet-ne-01"
  resource_group_name   = azurerm_resource_group.tf_rg_ne.name
  virtual_network_name  = azurerm_virtual_network.tf_vnet_ne.name
  address_prefixes      = ["10.0.1.0/24"]
}

# Sub net 2
resource "azurerm_subnet" "tf_snet_ne_02" {
  name                  = "tf-snet-ne-02"
  resource_group_name   = azurerm_resource_group.tf_rg_ne.name
  virtual_network_name  = azurerm_virtual_network.tf_vnet_ne.name
  address_prefixes      = [ "10.0.2.0/24" ]
}

# Storage account
resource "azurerm_storage_account" "tfstane" {
  name                      = "tfstane01"
  resource_group_name       = azurerm_resource_group.tf_rg_ne.name
  location                  = azurerm_resource_group.tf_rg_ne.location
  account_tier              = "Standard"
  account_replication_type  = "LRS"

  network_rules {
    default_action              = "Deny"
    virtual_network_subnet_ids  = [azurerm_subnet.tf_snet_ne_02.id]
  }
}

# File share
resource "azurerm_storage_share" "tf_fs_ne" {
  name                  = "documents"
  storage_account_name  = azurerm_storage_account.tfstane.name
  quota                 = 50
}


# Public ip
resource "azurerm_public_ip" "tf-pip-ne" {
  name                  = "tf-pip-ne-01"
  resource_group_name   = azurerm_resource_group.tf_rg_ne.name
  location              =  azurerm_resource_group.tf_rg_ne.location
  allocation_method     = "Static"
}


# Network Interface
resource "azurerm_network_interface" "tf-nwi-ne" {
  name                  = "tf-nwi-ne-01"
  resource_group_name   = azurerm_resource_group.tf_rg_ne.name
  location              = azurerm_resource_group.tf_rg_ne.location

  ip_configuration {
    name                            = "tf-conf-ne-01"
    subnet_id                       = azurerm_subnet.tf_snet_ne_02.id
    private_ip_address_allocation   = "Static"
  }
}


# Variables 
locals {
  backend_address_pool_name      = "${azurerm_virtual_network.tf_vnet_ne.name}-beap"
  frontend_port_name             = "${azurerm_virtual_network.tf_vnet_ne.name}-feport"
  frontend_ip_configuration_name = "${azurerm_virtual_network.tf_vnet_ne.name}-feip"
  http_setting_name              = "${azurerm_virtual_network.tf_vnet_ne.name}-be-htst"
  listener_name                  = "${azurerm_virtual_network.tf_vnet_ne.name}-httplstn"
  request_routing_rule_name      = "${azurerm_virtual_network.tf_vnet_ne.name}-rqrt"
  redirect_configuration_name    = "${azurerm_virtual_network.tf_vnet_ne.name}-rdrcfg"

}   


# Application gateaway
resource "azurerm_application_gateway" "tf-agw-ne" {
  name                  = "tf-agw-ne-01"
  resource_group_name   = azurerm_resource_group.tf_rg_ne.name
  location              = azurerm_resource_group.tf_rg_ne.location

  sku {
    name     = "Standard_v2"
    tier     = "Standard_v2"
    capacity = 2
  }

  gateway_ip_configuration {
    name      = "tf-gwip-config"
    subnet_id = azurerm_subnet.tf_snet_ne_01.id
  }

  frontend_port {
    name = local.frontend_port_name
    port = 80
  }

  frontend_ip_configuration {
    name                 = local.frontend_ip_configuration_name
    public_ip_address_id = azurerm_public_ip.tf-pip-ne
  }

  backend_address_pool {
    name = local.backend_address_pool_name
  }

  backend_http_settings {
    name                    = local.http_setting_name
    cookie_based_affinity   = "Disabled"
    path                    = "/path"
    port                    = 80
    protocol                = "Http"
    request_timeout         = 60
  }

  http_listener {
    name                            = local.listener_name
    frontend_ip_configuration_name  = local.frontend_ip_configuration_name
    frontend_port_name              = local.frontend_port_name
    protocol                        = "Http"
  }

  request_routing_rule {
    name                        = local.request_routing_rule_name
    priority                    = 305
    rule_type                   = "Basic"
    http_listener_name          = local.listener_name
    backend_address_pool_name   = local.backend_address_pool_name
    backend_http_settings_name  = local.http_setting_name
  }
}


# VM 1
resource "azurerm_windows_virtual_machine" "tf-vm-ne1" {
  name                  = "tf-vm-ne-01"
  resource_group_name   = azurerm_resource_group.tf_rg_ne.name
  location              = azurerm_resource_group.tf_rg_ne.location
  size               = "Standard_B2s"

  computer_name  = "Juvenal Baera"
  admin_username = "Juvenal Baera"
  admin_password = "Juven@l15b"

  network_interface_ids = [ azurerm_network_interface.tf-nwi-ne.id ]

  os_disk {
    caching = "ReadWrite"
    storage_account_type = "Standard_LRS"
  }

  source_image_reference {
    publisher = "MicrosoftWindowsServer"
    offer     = "WindowsServer"
    sku       = "2019-datacenter-gensecond"
    version = "latest"
  }
}


# VM 2
resource "azurerm_windows_virtual_machine" "tf-vm-ne2" {
  name                  = "tf-vm-ne-02"
  resource_group_name   = azurerm_resource_group.tf_rg_ne.name
  location              = azurerm_resource_group.tf_rg_ne.location
  size                  = "Standard_B2s"

  computer_name         = "Juvenal Baera"
  admin_username        = "Juvenal Baera"
  admin_password        = "Juven@l15b"

  network_interface_ids = [ azurerm_network_interface.tf-nwi-ne.id ]

  os_disk {
    caching              = "ReadWrite"
    storage_account_type = "Standard_LRS"
  }

  source_image_reference {
    publisher = "MicrosoftWindowsServer"
    offer     = "WindowsServer"
    sku       = "2019-datacenter-gensecond"
    version   = "latest"
  }
}

